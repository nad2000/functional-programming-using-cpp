#include <fplus/fplus.hpp>
#include <iostream>

using namespace fplus;
using namespace std;

typedef vector<int> Ints;
typedef vector<string> Strings;


result<string, string> get_intput_filepath(const Strings& args) {
	assert(args.size() > 0);
	if (args.size() != 2) return error<string, string>(
		"Usage: " + args[0] + " FILEPATH");
	else return ok<string,string>(args[1]);
}


result<string, string> read_file(const string& filepath) {

	const auto maybe_content = read_text_file_maybe(filepath)();
	const auto trimmed = lift_maybe(
		trim_whitespace<string>, maybe_content);
	return from_maybe(
		string("Unable to open file ") + filepath, trimmed);
}

result<Ints, string> parse_content(const string& content) {
	const auto maybe_values = fwd::apply(content
		, fwd::split(',', false)
		, fwd::transform(read_value<int>));
	if (all_by(is_just<int>, maybe_values)) 
		return ok<Ints, string>(justs(maybe_values));
	else
		return error<Ints, string>("Can not parse file.");
}

result<int, string> calc_median(const Ints& xs) {
	if (is_not_empty(xs))
		return ok<int, string>(median(xs));
	return error<int, string>("Need at least one value.");
}

string show_median(int value) {
	return "The median is " + show(value);
}

string show_error(const string& error) {
	return "ERROR: " + error;
}


// and_then : ((a -> Maybe b), (Maybe a)) -> Maybe b
template <typename Res, typename F, typename A> 
maybe<Res> and_then(F f, const maybe<A>& m) {
	if (is_just(m)) return f(unsafe_get_just(m));
	else return nothing<Res>();
}

template <typename Res, typename Error, typename F, typename A>
result<Res, Error> and_then_result_0(F f, const result<A, Error>& r) {
	if (is_ok(r)) return f(unsafe_get_ok(r));
	else return error<Res, Error>(r.unsafe_get_error());
};

int main(int argc, char* argv[]) {
	const Strings arguments(argv, argv + argc);
	const string error_msg = "An error occured.";
	const auto input_fp = get_intput_filepath(arguments);
	auto content = and_then_result_0<string>(read_file, input_fp);
	auto values = and_then_result_0<Ints>(parse_content, content);
	auto res = and_then_result_0<int>(calc_median, values);

	const auto output = unify_result(show_median, show_error, res);
	cout << output << endl;
}
