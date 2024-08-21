#pragma once
#include <list>
#include <string>
#include "SubOutput.h"
#include <ctime>

class CmdHandler{
    size_t N_pack;
    size_t bracket_counter = 0;
    std::list<std::string> cmd_list;
    std::list<SubOutputBase*> sub_ptr_list;
    time_t firstCmdTime;
public:
    CmdHandler(size_t N) : N_pack(N) {}
    ~CmdHandler();

    void process(const std::string&, time_t);
    void registerSub(SubOutputBase* ptr) { sub_ptr_list.push_back(ptr); }
    void updateSub();
};