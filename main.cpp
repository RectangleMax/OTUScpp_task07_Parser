#include <iostream>
#include "CmdHandler.h"
#include "SubOutput.h"
#include <ctime>

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "One argument is required." << std::endl;
        return 1;
    }
    int N_pack;
    try {
        N_pack = std::stoi(argv[1]);
    } catch (...) {
        std::cerr << "Incorrect argument." << std::endl;
        return 1;
    }

    CmdHandler hand_(N_pack);
    SubOutputCout ob1;
    SubOutputFile ob2;
    hand_.registerSub(&ob1);
    hand_.registerSub(&ob2);


    for (std::string cmd; std::getline(std::cin, cmd);){
        hand_.process(cmd, time(0));
    }
    return 0;
}

