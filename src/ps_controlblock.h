#include <vector>
#include <string>

enum ps_state {
    NEW, READY, RUN, WAIT, EXIT
};

class ps_controlblock {
    unsigned int process_id;
    std::string process_name;
    std::vector<std::string> text_section;
    unsigned int program_counter;

    ps_state state;

public:
    ps_controlblock(std::string, std::vector<std::string>);
    void set_text_section(std::vector<std::string>);
    std::string get_code_line(void);
    void set_state(ps_state);
    std::string get_process_name(void);
    int get_process_id(void);
};
