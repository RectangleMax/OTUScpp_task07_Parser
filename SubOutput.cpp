#include "SubOutput.h"

void SubOutputBase::outputFormat(std::ostream& ostr, const std::list<std::string>& cmd_list) {
    bool flag = true;
    for (auto& cmd_ : cmd_list) {
        if (flag) { 
            flag = false;
        } else {
            ostr << ", ";
        }
        ostr << cmd_;
    }
    ostr << std::endl;
}

void SubOutputCout::update(const std::list<std::string>& cmd_list, time_t) {
    outputFormat(std::cout, cmd_list);
}

void SubOutputFile::update(const std::list<std::string>& cmd_list, time_t time_) {
    std::ofstream file("bulk" + std::to_string(time_) + ".log");
    outputFormat(file, cmd_list);
}