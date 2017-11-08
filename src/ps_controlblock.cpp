#include "ps_controlblock.h"
#include <iostream>

ps_controlblock::ps_controlblock(std::vector<std::string> text_vector) {
    text_section = text_vector;
    program_counter_it = text_section.begin();
    state = NEW;
}

std::string ps_controlblock::get_code_line(void) {
    if (program_counter_it == text_section.end()) {
        return "";
    }
    std::string line = *program_counter_it;
    
    program_counter_it++;
    return line;
}

void ps_controlblock::set_state(ps_state s) {
    state = s;
}
