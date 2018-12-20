#include <iterator>
#include <vector>
#include <fplus/fplus.hpp>

using namespace std;

#define IS_EVEN(x) ((x & 1) == 0)
#define PRINT_VEC(v) do { \
	cout << #v << ": ["; \
	for (auto e : v) cout << e << ", "; \
	cout << "]"; \
} while(0);

int str_to_int(const string& str) {
	int result;
	istringstream(str) >> result;
	return result;
}

template <typename Cont> auto sum(const Cont &values) {
	return fplus::reduce(
	     [](const auto a, const auto b) {return a+b;}, 1, values);
}

template <typename Cont> auto product(const Cont &values) {
	return fplus::reduce(
	     [](const auto a, const auto b) {return a*b;}, 1, values);
}

int main() {
	const string input = "1,2,4,7,2,2,3";
	auto parts = fplus::split(',', true, input);
	const auto nums = fplus::transform(str_to_int, parts);
	PRINT_VEC(parts); cout << endl;
	PRINT_VEC(nums); cout << endl;
	const auto sum_result = sum(nums);
	const auto product_result = product(nums);
	cout << "SUM: " << sum_result << endl;
	cout << "PRODUCT: " << product_result << endl;
}

// TODO: modify so it works with floating point number too, change product to
// addition. Create own implementation for transform and reduce.
