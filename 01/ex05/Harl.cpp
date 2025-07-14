#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "Hmmm ... im debugging" << std::endl;
}

void Harl::info(void)
{
    std::cout << "Do you know that C++ is based of C?" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Next time, dont forget to deallocate memory using delete!" << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! the code has segfaulted" << std::endl;
}

void Harl::complain(std::string level)
{
    int size = 4;
    std::string arr[size] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int j = 0; j < size; j++)
    {
        if (arr[j] == level)
        {
            (this->*ptr[j])();
            return ;
        }
    }
    std::cout << "Who are you? I dont know you!" << std::endl;
}