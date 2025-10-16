#include "RPN.hpp"

int main(int ac, char **av)
{

    try
    {
        if (ac != 2)
        {
            std::cerr << "Error: Number of args is not valid." << std::endl;
            return 1;
        }
        RPN rpn(av[1]);
        rpn.executeExpression();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}