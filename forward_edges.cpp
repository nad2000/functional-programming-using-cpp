#include <iostream>
#include <fplus/fplus.hpp>
#include <math.h>

using namespace std;

typedef pair<float, float> point;
typedef pair<point, point> edge;
typedef vector<point> points;

inline float distance(const point& p1, const point& p2) {
	const auto dx = p2.first - p1.first;
	const auto dy = p2.second - p1.second;
	return sqrt(dx*dx + dy*dy);
}

inline const float edge_length(const edge& e) {
      return distance(e.first, e.second);
}

int main() {

	const points polygon =  { {1, 2}, {7, 3}, {6, 5}, {4 ,4}, {2, 9} };
	using namespace fplus;
	const auto result2 = fwd::apply(polygon
		, fwd::overlapping_pairs_cyclic()
		, fwd::maximum_on(edge_length));
	cout << fplus::show(result2) <<endl;
}


