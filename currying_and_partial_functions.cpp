#include <iostream>
#include <fplus/fplus.hpp>

#define IS_EVEN(x) (!(x & 1))
#define PRINT_VEC(v) do { \
	cout << #v << ": ["; \
	for (auto e : v) cout << e << ", "; \
	cout << "]" << endl; \
} while(0);

using namespace std;

const int square(int v) {return v * v;}

int main() {
	vector<vector<int>> xss = {{0,1,2}, {3,4,5}};
	const auto yss = fplus::transform(
	  [](auto s) {return fplus::transform(square, s);}, xss);
	cout << fplus::show(yss) <<endl;

	auto add_four = [](auto v1){
		return [v1](auto v2) {
			return [v1,v2](auto v3){
				return [v1,v2,v3](auto v4){
					return v1+v2+v3+v4;
				};
			};
		};
	};
	cout << "ADD FOUR: " << add_four(1)(2)(3)(4) << endl;
}
