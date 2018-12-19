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

int main() {
	const string input = "1,2,4,7,2,2,3";
	auto parts = fplus::split(',', true, input);
	const auto nums = fplus::transform(str_to_int, parts);
	PRINT_VEC(parts); cout << endl;
	PRINT_VEC(nums); cout << endl;
	const auto result = fplus::reduce(multiplies<int>(), 1, nums);
	cout << "RESULT: " << result << endl;
}

// TODO: modify so it works with floating point number too, change product to
// addition. Create own implementation for transform and reduce.
