#include <iostream>
#include "mylib_T.h"

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "One argument is required." << std::endl;
        return 1;
    }
    int n_cmd_group;
    try {
        n_cmd_group = std::stoi(argv[1]);
    } catch (...) {
        std::cerr << "Incorrect argument." << std::endl;
        return 1;
    }

    std::list<std::string> list_cmd;
    int bracket_counter = 0;
    for (std::string cmd; std::getline(std::cin, cmd);){
        if (cmd == "{") {
            if (!bracket_counter++) { 
                output_and_clear_list(list_cmd);
            }
            continue;
        } else if (cmd == "}") {
            if (!--bracket_counter) {
                output_and_clear_list(list_cmd);
            }
            continue;
        } 
        list_cmd.push_back(cmd);
        if (!bracket_counter) {
            if (list_cmd.size() == n_cmd_group) {
                output_and_clear_list(list_cmd);
            }
        }
    }
    if (bracket_counter) {
        list_cmd.clear();
    } else {
        output_and_clear_list(list_cmd);
    }
    return 0;
}

