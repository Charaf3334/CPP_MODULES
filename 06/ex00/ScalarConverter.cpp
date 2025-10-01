#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &theOtherObject)
{
    (void)theOtherObject;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &theOtherObject)
{
    if (this != &theOtherObject)
        (void)theOtherObject;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

static int appears(const std::string &str, char target)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == target)
            count++;
    }
    return count;
}

void ScalarConverter::convert(const std::string &str)
{
    int is_char = 0;
    int is_float = 0;
    int is_int = 0;
    int is_double = 0;
    
    if (str[0] == '\'' && str[str.length() - 1] == '\'' && str.length() == 3)
        is_char = 1;
    else if (str[str.length() - 1] == 'f' && appears(str, 'f') == 1 && appears(str, '.') == 1 && str.length() >= 3)
        is_float = 1;
    else if (str.length() > 1 && appears(str, '.') == 1)
        is_double = 1;
    else
        is_int = 1;
    
    std::cout << "is_char: " << is_char << std::endl;
    std::cout << "is_float: " << is_float << std::endl;
    std::cout << "is_int: " << is_int << std::endl;
    std::cout << "is_double: " << is_double << std::endl;
}