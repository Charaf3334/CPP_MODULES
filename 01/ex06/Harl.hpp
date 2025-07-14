#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    private:
        void debug();
        void info();
        void warning();
        void error();
        std::string level;
    public:
        Harl(std::string level);
        void getLevel(std::string level);
        int indexing();
};

#endif