#include <iostream>
#include <fplus/fplus.hpp>

#define IS_EVEN(x) (!(x & 1))
#define PRINT_VEC(v) do { \
	cout << #v << ": ["; \
	for (auto e : v) cout << e << ", "; \
	cout << "]" << endl; \
} while(0);

using namespace std;

const auto is_even = [](int x) -> bool {return IS_EVEN(x);};

vector<int> xs = {0,1,1,2,3,4,5,6};
const auto ys = fplus::keep_if(is_even, xs);
const auto ys2 = fplus::keep_if([](int x) -> bool {return IS_EVEN(x);}, xs);

int main() {
	PRINT_VEC(xs);
	PRINT_VEC(ys);
	PRINT_VEC(ys2);

	auto val = 42;
	// allow mutation (if given by reference)
	const auto add_value = [&val](int x) -> int {return x + val;};
	cout << add_value(42) << endl;
	val = 100;
	cout << add_value(42) << endl;
	// in not, it capures the value
	val = 42;
	const auto add_value2 = [val](int x) -> int {return x + val;};
	cout << add_value2(42) << endl;
	val = 100;
	cout << add_value2(42) << endl;
	// New C++14 feature (no need to specify return type nor input type.
	// lambda will work as a template:
	const auto add_value3 = [&val](auto x) {return x + val;};
	val = 42;
	cout << add_value3(42) << endl;
	val = 100;
	cout << add_value3(42) << endl;
}
