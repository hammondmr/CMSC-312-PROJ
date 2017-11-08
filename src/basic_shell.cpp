// Basic shell...
// Runs a loop reading line input into string
// Processes string based on process_input(std::string input) method

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "basic_shell.h"

std::string input_line = "";

using namespace std;

int process_input(std::string input) {

    vector<string> args = parse_arguments(input);

	if (args.size() < 1) {
        return EXIT_SUCCESS;
    }
    if (args[0] == "EXEC") {
		std::cout << "executing..." << std::endl;
		std::cout << "done." << std::endl;
		return EXIT_SUCCESS;
	}
	if (args[0] == "LOAD") {
		std::cout << "loading..." << std::endl;
        
        std::string file_name = args[1];
        std::ifstream loadfile;

        loadfile.open("text_files/" + file_name);
    
        std::vector<string> code_lines;
        std::string line;

        while(!loadfile.eof()) {
            std::getline(loadfile, line);
            std::cout << line << std::endl;
        }

        loadfile.close();
    
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
