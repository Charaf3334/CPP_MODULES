#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &theOtherObject);
        ScalarConverter& operator=(const ScalarConverter &theOtherObject);
    public:
        ~ScalarConverter();
        static void convert(const std::string &str);
};

#endif