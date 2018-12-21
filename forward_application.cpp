#include <fplus/fplus.hpp>
#include <iostream>

using namespace std;

#define IS_EVEN(x) ((x & 1) == 0)
#define PRINT_VEC(v) do { \
	cout << #v << ": ["; \
	for (auto e : v) cout << e << ", "; \
	cout << "]"; \
} while(0);

const auto str_to_int = fplus::read_value_unsafe<int>;

int main() {
	using namespace fplus;
	const string input = "1,2,4,7,2,2,3";
	const auto result = fwd::apply(input
		, fwd::split(',', false)
		, fwd::transform(str_to_int)
		, fwd::product());
	cout << "RESULT: " << result << endl;
}
