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

void SubOutputCout::update(const std::list<std::string>& cmd_list) {
    outputFormat(std::cout, cmd_list);
}

void SubOutputFile::update(const std::list<std::string>& cmd_list) {
    std::ofstream file("bulk" + std::to_string(time(0)) + ".txt");
    outputFormat(file, cmd_list);
}