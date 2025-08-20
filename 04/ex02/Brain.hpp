#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &theOtherObject);
        Brain& operator=(const Brain &theOtherObject);
        ~Brain();
};

#endif