#include "CmdHandler.h"

CmdHandler::~CmdHandler() { 
    if (!bracket_counter) {
        updateSub();
    }
    cmd_list.clear();
}

void CmdHandler::process(const std::string& cmd, time_t cmd_time) {
    if (cmd == "{") {
        if (!bracket_counter++) { 
            updateSub();
            cmd_list.clear();
        }
        return;
    } else if (cmd == "}") {
        if (!--bracket_counter) {
            updateSub();
            cmd_list.clear();
        }
        return;
    } 
    if (cmd_list.empty())
        firstCmdTime = cmd_time;
    cmd_list.push_back(cmd);
    if (!bracket_counter) {
        if (cmd_list.size() == N_pack) {
            updateSub();
            cmd_list.clear();
        }
    }
}

void CmdHandler::updateSub(){
    for (auto it = sub_ptr_list.begin(); it != sub_ptr_list.end(); ++it) {    
        (*it)->update(cmd_list, firstCmdTime);
    }
}
