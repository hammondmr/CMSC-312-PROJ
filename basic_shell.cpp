// Basic shell...
// Runs a loop reading line input into string
// Processes string based on process_input(std::string input) method

#include <string>
#include <iostream>
#include <cstdlib>

std::string input_line = "";

int process_input(std::string input) {

	if (input == "EXEC") {
		std::cout << "executing..." << std::endl;
		std::cout << "done." << std::endl;
		return EXIT_SUCCESS;
	}
	if (input == "LOAD") {
		std::cout << "loading..." << std::endl;
		std::cout << "done." << std::endl;
		return EXIT_SUCCESS;
	}
	if (input == "EXIT") {
		std::cout << "exiting..." << std::endl;
		exit(0);
		return EXIT_SUCCESS;
	}
	else {
		std::cout << "invalid command." << std::endl;
		return EXIT_SUCCESS;
	}
}

void shell_loop() {
	while (true) {
		std::cout << "command: ";
		std::getline(std::cin, input_line);
		process_input(input_line);
	}
}

int main()
{
	shell_loop();
}



