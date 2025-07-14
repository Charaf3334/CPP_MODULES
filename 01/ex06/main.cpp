#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error: number of arguments not valid" << std::endl;
        return 1;
    }

    Harl harl(av[1]);

    switch (harl.indexing())
    {
        case 1:
            harl.getLevel("DEBUG");
            harl.getLevel("INFO");
            harl.getLevel("WARNING");
            harl.getLevel("ERROR");
            break;
        case 2:
            harl.getLevel("INFO");
            harl.getLevel("WARNING");
            harl.getLevel("ERROR");
            break;
        case 3:
            harl.getLevel("WARNING");
            harl.getLevel("ERROR");
            break;
        case 4:
            harl.getLevel("ERROR");
            break;
        default:
            std::cout << "Who are you? I dont know you!" << std::endl;
    }

    return (0);
}