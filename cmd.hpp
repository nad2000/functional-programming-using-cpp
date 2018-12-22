#include <fplus/fplus.hpp>
#include <iostream>

template<typename F> void cmd_line_interact(F f) {
	const std::string input (
		std::istreambuf_iterator<char>(std::cin.rdbuf()),
		std::istreambuf_iterator<char>());

	std::string output = f(input);

	std::cout << output << std::endl;
}

