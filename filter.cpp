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

bool is_even(int x) {
	return IS_EVEN(x);
}

vector<int> xs = {0, 1, 2, 3, 4};

const auto ys = fplus::keep_if(is_even, xs);

int main() {
	vector<int> ys;
	for (auto x : xs) if (IS_EVEN(x)) ys.push_back(x);
	PRINT_VEC(xs); cout << endl;
	PRINT_VEC(ys); cout << endl;
}
