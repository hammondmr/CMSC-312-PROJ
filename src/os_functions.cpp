#include "os_functions.h"

#include <fstream>
#include <iostream>
#include <vector>

int load(std::string file_name) {
    
    ifstream loadfile;
    loadfile.open("text_files/" + file_name);
    
    std::vector<string> code_lines;
    std::string line;

    while(!loadfile.eof()) {
        loadfile >> line;
        std::cout << line << std::endl;
    }
    return 0;
}
