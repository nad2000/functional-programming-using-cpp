#include <fplus/fplus.hpp>
#include <iostream>

using namespace std;
using namespace fplus;

int main() {
	const string input (
		istreambuf_iterator<char>(cin.rdbuf()),
		istreambuf_iterator<char>());
	
	string output = fwd::apply(input
		, fwd::split_lines(false)
		, fwd::sort()
		, fwd::join(string("\n")));

	cout << output << endl;
}
