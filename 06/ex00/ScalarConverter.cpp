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

static void printing(const std::string &_char, const std::string &_int, const std::string _float, const std::string &_double)
{
    std::cout << "char: " << _char << std::endl;
    std::cout << "int: " << _int << std::endl;
    std::cout << "float: " << _float << std::endl;
    std::cout << "double: " << _double << std::endl;
}

static int valid_sign(const std::string &str)
{
    if (str.length() == 1 && (str[0] == '-' || str[0] == '+'))
        return 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (i > 0 && (str[i] == '-' || str[i] == '+'))
            return 0;
    }
    return 1;
}

static int all_digit(const std::string &str, int double_flag)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (double_flag)
        {
            if (str[i] == '.')
                continue;
        }
        if (str[i] == '+' || str[i] == '-')
            continue;
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

void ScalarConverter::convert(const std::string &str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        printing("impossible", "impossible", str + 'f', str);
        return;
    }
    else if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        printing("impossible", "impossible", str, str.substr(0, str.length() - 1));
        return;
    }
    else if (str[0] == '\'' && str[str.length() - 1] == '\'' && str.length() == 3)
    {
        char c = str[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    else if (str[str.length() - 1] == 'f' && appears(str, 'f') == 1 && appears(str, '.') == 1 && str.length() >= 3 && valid_sign(str))
    {
        float num = atof(str.c_str());
        int overflow = atoi(str.c_str());
        float fraction = num - floor(num);
        if (!isprint(static_cast<unsigned char>(overflow)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(num) << std::endl;
        std::cout << "float: " << num << (!fraction ? ".0f" : "f") << std::endl;
        std::cout << "double: " << static_cast<double>(num) << (!fraction ? ".0" : "") << std::endl;
        return;
    }
    else if (str.length() > 1 && appears(str, '.') == 1 && valid_sign(str) && all_digit(str, 1))
    {
        double num = atof(str.c_str());
        int overflow = atoi(str.c_str());
        double fraction = num - floor(num);
        if (!isprint(static_cast<unsigned char>(overflow)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(num) << std::endl;
        std::cout << "float: " << static_cast<float>(num) << (!fraction ? ".0f" : "f") << std::endl;
        std::cout << "double: " << num << (!fraction ? ".0" : "") << std::endl;
        return;
    }
    else if (str.length() >= 1 && valid_sign(str) && all_digit(str, 0))
    {
        int num = atoi(str.c_str());
        if (!isprint(static_cast<unsigned char>(num)))
        {
            std::cout << "here\n";
            std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        std::cout << "int: " << num << std::endl;
        std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl; 
        std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl; 
        return;
    }
    else
        printing("impossible", "impossible", "impossible", "impossible");
}