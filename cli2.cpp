#include "cmd.hpp"

using namespace fplus;

int main() {
	cmd_line_interact(
		fwd::compose(fwd::split_lines(false)
			, fwd::sort()
			, fwd::join(string("\n"))));
}

