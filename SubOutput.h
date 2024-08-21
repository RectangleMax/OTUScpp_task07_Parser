#pragma once
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <fstream>

struct SubOutputBase{
    void outputFormat(std::ostream&, const std::list<std::string>&);
// почему не компилиутеся без "=0"?
    virtual void update(const std::list<std::string>&) = 0;
    virtual ~SubOutputBase() {}
};

struct SubOutputCout : SubOutputBase {
    void update(const std::list<std::string>&) override;
};

struct SubOutputFile : SubOutputBase {
    void update(const std::list<std::string>&) override;
};