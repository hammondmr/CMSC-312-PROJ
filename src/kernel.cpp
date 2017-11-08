#include "kernel.h"
#include "ps_controlblock.h"
#include <fstream>
#include <iostream>

std::vector<ps_controlblock> pcb_chain;
std::queue<ps_controlblock> ready_queue;

void load_program(std::string filename) {
    
    std::ifstream loadfile;
    loadfile.open("text_files/" + filename);

    std::vector<std::string> code_lines;
    std::string line;

    while(!loadfile.eof()) {
        std::getline(loadfile, line);
        code_lines.push_back(line);
        std::cout << "*" + line << std::endl;
    }

    loadfile.close();
    
    ps_controlblock new_pcb(code_lines);
    pcb_chain.push_back(new_pcb);
    ready_queue.push(new_pcb);
    new_pcb.set_state(READY);
}

void execute(int num_cycles) {
    ps_controlblock next_pcb = ready_queue.front();
    ready_queue.pop();
    ready_queue.push(next_pcb);
    
    for (int i = 0; i < num_cycles; i++) {
        std::cout << next_pcb.get_code_line();
        std::cout << std::endl;
    }
}

