#include "BitcoinExchange.hpp"

int main(int ac, const char **av)
{
    try
    {
        if (ac != 2)
        {
            std::cerr << "Error: number of args is not valid." << std::endl;
            return 1;
        }
        BitcoinExchange btc(av[1]);
        btc.readDatabase("data.csv");
        btc.checkFile();
        btc.printingValues();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}