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

// own implementation of keep_if
template <typename F, typename T> vector<T> keep_if0(F f, const vector<T>& xs) {
	vector<T> ys;
	for (auto v: xs) if (f(v)) ys.push_back(v);
	return ys;
}

int main() {
	vector<int> ys;
	for (auto x : xs) if (IS_EVEN(x)) ys.push_back(x);
	const auto ys2 = fplus::keep_if(is_even, xs);
	const auto ys0 = keep_if0(is_even, xs);
	PRINT_VEC(xs); cout << endl;
	PRINT_VEC(ys); cout << endl;
	PRINT_VEC(ys2); cout << endl;
	PRINT_VEC(ys0); cout << endl;
}
