#include "ps_controlblock.h"
#include <iostream>

unsigned int unique_identifier = 0;
int get_unique_identifier(void) {
    unique_identifier++;
    return unique_identifier - 1;
}

ps_controlblock::ps_controlblock(std::string ps_name, std::vector<std::string> text_vector) {
    process_id = get_unique_identifier();
    process_name = ps_name;
    text_section = text_vector;
    program_counter = 0;
    state = NEW;
}

std::string ps_controlblock::get_code_line(void) {
    if (program_counter >= text_section.size()) {
        return "";
    }
    std::string line = text_section[program_counter];
    program_counter++;
    if(line == "") {
        return get_code_line();
    } else {
        return line;
    }
}

void ps_controlblock::set_state(ps_state s) {
    state = s;
}

std::string ps_controlblock::get_process_name() {
    return process_name;
}

int ps_controlblock::get_process_id(void) {
    return process_id;
}
