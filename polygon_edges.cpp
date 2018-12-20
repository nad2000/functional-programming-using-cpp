#include <iostream>
#include <fplus/fplus.hpp>
#include <math.h>

#define IS_EVEN(x) (!(x & 1))
#define PRINT_VEC(v) do { \
	cout << #v << ": ["; \
	for (auto e : v) cout << e << ", "; \
	cout << "]" << endl; \
} while(0);

#define PRINT_POLYGON(P) do { \
	cout << #P << ": ["; \
	for (auto p : P) cout << "{" << p.first \
	<< ", " << p.second << "}," << endl; \
	cout << "]" << endl; \
} while(0);

using namespace std;

typedef pair<float, float> point;

float distance(const point& p1, const point& p2) {
	auto const dx = p2.first - p1.first;
	auto const dy = p2.second - p1.second;
	return sqrt(dx*dx + dy*dy);
}

int main() {

	vector<point> polygon =  { {1, 2}, {7, 3}, {6, 5}, {4 ,4}, {2, 9} };
	// Find the longest edge of the polygon.
	int p1, p2;
	float md = 0.0;
	for (auto i=0; i<polygon.size(); ++i)
		for (auto j=i+1; j<polygon.size(); ++j) {
			auto const d = distance(polygon[i], polygon[j]);
			if (d > md) {
				p1 = i;
				p2 = j;
				md = d;
			}
		}
	PRINT_POLYGON(polygon);
	cout << "P1: " << p1 << endl;
	cout << "P2: " << p2 << endl;
	cout << "D: " << md << endl;

	const auto edges = fplus::overlapping_pairs_cyclic(polygon);
	const auto result = fplus::maximum_on(
		      [](auto e) {return distance(e.first, e.second);}, edges);
	cout << fplus::show(result) <<endl;
}




