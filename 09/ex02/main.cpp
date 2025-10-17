#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
        {
            std::cerr << "Error: Number of args is not valid." << std::endl;
            return 1;
        }
        PmergeMe obj(av);
        if (obj.alreadySorted() || ac == 2)
            std::cout << "Already sorted!" << std::endl;
        else
        {
            obj.sortVector();
            obj.sortDeque();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}