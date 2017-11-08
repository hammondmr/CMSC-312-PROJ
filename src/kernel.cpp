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
    }

    loadfile.close();
    
    ps_controlblock new_pcb(filename, code_lines);
    pcb_chain.push_back(new_pcb);
    ready_queue.push(new_pcb);
    new_pcb.set_state(READY);
}

void execute(int num_cycles) {
    //ready_queue.pop();
    //ready_queue.push(next_pcb);
    std::string line = "";
    std::string process_name = "";
    unsigned int process_id;
    for (int i = 0; i < num_cycles; i++) {
        // eof
        line = ready_queue.front().get_code_line();
        while(line == "" && ready_queue.size() > 0) {
            ready_queue.pop();
            line = ready_queue.front().get_code_line();
        } if (ready_queue.size() == 0) {
            std::cout << "ready queue empty";
            return;
        }
        process_name = ready_queue.front().get_process_name();
        process_id = ready_queue.front().get_process_id();
        std::cout << "executing: " << process_name << "(" << process_id << ") - " <<  line << std::endl;
    }
}

