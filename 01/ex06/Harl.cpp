#include "Harl.hpp"

Harl::Harl(std::string level)
{
    this->level = level;
}

int Harl::indexing()
{
    std::string level = this->level;
    
    if (level == "DEBUG") return 1;
    if (level == "INFO") return 2;
    if (level == "WARNING") return 3;
    if (level == "ERROR") return 4;
    return (0);
}

void Harl::getLevel(std::string level)
{
    if (level == "DEBUG")
        this->debug();
    else if (level == "INFO")
        this->info();
    else if (level == "WARNING")
        this->warning();
    else if (level == "ERROR")
        this->error();
}

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