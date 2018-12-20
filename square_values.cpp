#include <algorithm>
#include <iterator>
#include <vector>
#include <fplus/fplus.hpp>

using namespace std;

typedef std::vector<int> Inst;
int square(int x) {
	return x * x;
}

Inst square_vec_goto(const Inst& xs) {
	Inst ys;
	ys.reserve(xs.size());
	auto it = begin(xs);
loopBegin:
	if (it == end(xs)) goto loopEnd;
	ys.push_back(square(*it));
	++it;
	goto loopBegin;
loopEnd:
	return ys;
}


Inst square_vec_for0(const Inst& xs) {
	Inst ys;
	ys.reserve(xs.size());
	for(auto i=0; i<xs.size(); ++i) ys.push_back(xs[i]);
	return ys;
}

Inst square_vec_while(const Inst& xs) {
	Inst ys;
	ys.reserve(xs.size());
	auto it = begin(xs);
	while (it != end(xs)) {
		ys.push_back(square(*it));
		++it;
	}
	return ys;
}

Inst square_vec_for(const Inst& xs) {
	Inst ys;
	ys.reserve(xs.size());
	for (auto it = begin(xs); it != end(xs); ++it) ys.push_back(square(*it));
	return ys;
}

Inst square_vec_range_based_for(const Inst& xs) {
	Inst ys;
	ys.reserve(xs.size());
	for (int x: xs) ys.push_back(square(x));
	return ys;
}


// STL provides std_transform
Inst square_vec_std_trsnsform(const Inst& xs) {
	Inst ys;
	ys.reserve(xs.size());
	transform(begin(xs), end(xs), back_inserter(ys), square);
	return ys;
}

// This is a higher order function... a function that uses anoter function as an
// input.
template <typename F, typename T> vector<T> transform_vec(F f, const vector<T>& xs) {
	vector<T> ys;
	ys.reserve(xs.size());
	transform(begin(xs), end(xs), back_inserter(ys), f);
	return ys;
}

// Maximally readable code:
Inst sqr_transform_vec(const Inst& xs) {
	return transform_vec(square, xs);
}

// Usgin fplus:
Inst sqr_fplus_vec(const Inst& xs) {
	return fplus::transform(square, xs);
}


int main() {
	Inst xs(8192);
	//for (auto i = 0; i < 65536; ++i) sqr_fplus_vec(xs);
	for (auto i = 0; i < 65536; ++i) square_vec_for0(xs);
	// for (auto i = 0; i < 65536; ++i) square_vec_goto(xs);
}
