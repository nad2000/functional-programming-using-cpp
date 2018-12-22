#include <fplus/fplus.hpp>
#include <iostream>

using namespace std;
using namespace fplus;

int costly_function(int x) {
	// something complicated...
	return 42 + x;
}

template <typename F>function<int(int)> memoize0(F f) {
	unordered_map<int, int> storage;
	return [f, storage](int x) mutable -> int {
		
		if (const auto it = storage.find(x); it == storage.end()) 
			return storage.insert(make_pair(x, f(x))).first->second;
		else
			return it->second;
	};
}

const auto c_f_memoized = memoize0(costly_function);

int main() {
	cout << c_f_memoized(11) << endl;
	cout << c_f_memoized(22) << endl;
	cout << c_f_memoized(11) << endl;
}

