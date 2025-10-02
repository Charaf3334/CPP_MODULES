#include "ScalarConverter.hpp"

int main(int ac, char **av) // overflow
{
    if (ac != 2)
    {
        std::cerr << "Error: number of args not valid" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}