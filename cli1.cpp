#include <fplus/fplus.hpp>
#include <iostream>

using namespace std;
using namespace fplus;

int main() {
	const string input (
		istreambuf_iterator<char>(cin.rdbuf()),
		istreambuf_iterator<char>());

	string output = to_upper_case(input);

	cout << output << endl;

}
