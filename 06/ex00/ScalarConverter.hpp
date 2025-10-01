#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>

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