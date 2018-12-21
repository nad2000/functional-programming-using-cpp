#include <fplus/fplus.hpp>
#include <iostream>

using namespace std;
using namespace fplus;

const auto str_to_int = fplus::read_value_unsafe<int>;
inline int square_int(int x) {return x * x;}

int main() {
	const string input = "1,2,4,7,2,2,3";
	const auto result = fwd::apply(input
		, fwd::split(',', false)
		, fwd::transform(str_to_int)
		, fwd::transform(square_int)
		, fwd::sum());
	cout << "RESULT: " << result << endl;

	const auto result2 = fwd::apply(input
		, fwd::split(',', false)
		, fwd::transform(fwd::compose(str_to_int, square_int))
		, fwd::sum());
	cout << "RESULT: " << result2 << endl;
}

