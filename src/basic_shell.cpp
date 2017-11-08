// Basic shell...
// Runs a loop reading line input into string
// Processes string based on process_input(std::string input) method

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "basic_shell.h"
#include "kernel.h"

std::string input_line = "";

using namespace std;

int process_input(std::string input) {

    vector<string> args = parse_arguments(input);

	if (args.size() < 1) {
        return EXIT_SUCCESS;
    }
    if (args[0] == "EXEC") {
		std::cout << "executing..." << std::endl;
        int cycles = 1;
        if(args.size() >= 2) {
            cycles = std::stoi(args[1], nullptr, 10);
        }
        execute(cycles);

		std::cout << "done." << std::endl;
		return EXIT_SUCCESS;
	}
	if (args[0] == "LOAD") {
		std::cout << "loading..." << std::endl;
        
        if(args.size() < 2) {
            std::cout << "no filename entered." << std::endl;
            return EXIT_FAILURE;
        }
        std::string file_name = args[1];
        
        load_program(file_name);
    
		std::cout << "done." << std::endl;
		return EXIT_SUCCESS;
	}
	if (args[0] == "EXIT") {
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
    std::string input_line = "";
    while (true) {
		std::cout << "> ";
		std::getline(std::cin, input_line);
		process_input(input_line);
	}
}

// using string iterators and vectors
// separates input into separate arguments in a vector
vector<string> parse_arguments(std::string str) {
    string next;
    vector<string> result;

    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ' ') {
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
        } else {
            next += *it;
        }
    }
    if (!next.empty()) {
        result.push_back(next);
    }
    return result;
}
