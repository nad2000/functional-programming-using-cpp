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
typedef pair<point, point> edge;
typedef vector<point> points;

inline float distance(const point& p1, const point& p2) {
	const auto dx = p2.first - p1.first;
	const auto dy = p2.second - p1.second;
	return sqrt(dx*dx + dy*dy);
}

inline const vector<edge> get_edges(const points& polygon) {
	return fplus::overlapping_pairs_cyclic(polygon);
}

inline const float edge_length(const edge& e) {
      return distance(e.first, e.second);
}

int main() {

	const points polygon =  { {1, 2}, {7, 3}, {6, 5}, {4 ,4}, {2, 9} };
	// Find the longest edge of the polygon.
	const auto result = fplus::maximum_on(edge_length, get_edges(polygon));
	cout << fplus::show(result) <<endl;
}

