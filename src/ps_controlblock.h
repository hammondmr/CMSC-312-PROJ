#include <vector>
#include <string>

enum ps_state {
    NEW, READY, RUN, WAIT, EXIT
};

class ps_controlblock {
    std::vector<std::string> text_section;
    std::vector<std::string>::iterator program_counter_it;

    ps_state state;

public:
    ps_controlblock(std::vector<std::string>);
    void set_text_section(std::vector<std::string>);
    std::string get_code_line(void);
    void set_state(ps_state);
};
