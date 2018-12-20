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

inline float distance(const point& p1, const point& p2) {
	auto const dx = p2.first - p1.first;
	auto const dy = p2.second - p1.second;
	return sqrt(dx*dx + dy*dy);
}

inline const vector<pair<point, point>> get_edges(const vector<point>& polygon) {
	return fplus::overlapping_pairs_cyclic(polygon);
}

inline const float edge_length(const pair<point, point>& e) {
      return distance(e.first, e.second);
}

int main() {

	vector<point> polygon =  { {1, 2}, {7, 3}, {6, 5}, {4 ,4}, {2, 9} };
	// Find the longest edge of the polygon.

	const auto edges = fplus::overlapping_pairs_cyclic(polygon);
	const auto result = fplus::maximum_on(edge_length, get_edges(polygon));
	cout << fplus::show(result) <<endl;
}

