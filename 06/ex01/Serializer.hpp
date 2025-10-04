#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

#define uintptr_t unsigned long

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &theOtherObject);
        Serializer& operator=(const Serializer &theOtherObject);
    public:
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif