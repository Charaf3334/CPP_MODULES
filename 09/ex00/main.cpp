#include "BitcoinExchange.hpp"

int main(int ac, const char **av)
{
    BitcoinExchange *btc = NULL;
    try
    {
        if (ac != 2)
        {
            std::cerr << "Error: number of args is not valid." << std::endl;
            return 1;
        }
        btc = new BitcoinExchange(av[1]);
        btc->readDatabase("data.csv");
        btc->checkFileAndPrint();

        delete btc;
        btc = NULL;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        if (btc)
            delete btc;
        return 1;
    }
    return 0;
}