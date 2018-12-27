#include <fplus/fplus.hpp>
#include <iostream>

using namespace fplus;
using namespace std;

typedef vector<int> Ints;
typedef vector<string> Strings;

maybe<string> get_intput_filepath(const Strings& args) {
	assert(args.size() > 0);
	if (args.size() != 2) return nothing<string>();
	else return just<string>(args[1]);
}


maybe<string> read_file(const string& filepath) {
	ifstream input(filepath);
	if (!input.good()) return nothing<string>();
	return just(trim_whitespace(string(
		istreambuf_iterator<string::value_type>(input),
		istreambuf_iterator<string::value_type>())));
}

maybe<Ints> parse_content(const string& content) {
	const auto maybe_values = fwd::apply(content
		, fwd::split(',', false)
		, fwd::transform(read_value<int>));
	if (all_by(is_just<int>, maybe_values)) 
		return just<Ints>(justs(maybe_values));
	else
		return nothing<Ints>();
}

maybe<int> calc_median(const Ints& xs) {
	if (is_not_empty(xs))
		return just<int>(median(xs));
	return nothing<int>();
}

string show_median(int value) {
	return "The median is " + show(value);
}


// and_then : ((a -> Maybe b), (Maybe a)) -> Maybe b
template <typename Res, typename F, typename A> 
maybe<Res> and_then(F f, const maybe<A>& m) {
	if (is_just(m)) return f(unsafe_get_just(m));
	else return nothing<Res>();
}

int main(int argc, char* argv[]) {
	const Strings arguments(argv, argv + argc);
	const string error_msg = "An error occured.";
	const auto input_fp = get_intput_filepath(arguments);
	auto content = and_then<string>(read_file, input_fp);
	auto values = and_then<Ints>(parse_content, content);
	auto res = and_then<int>(calc_median, values);

	const auto output = lift_maybe(show_median, res);
	cout << just_with_default(error_msg, output) << endl;
}


