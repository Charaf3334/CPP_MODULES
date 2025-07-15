#include <iostream>

int main(void)
{
    std::string s = "HI THIS IS BRAIN";

    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << "The memory address of s is: " << &s << std::endl;
    std::cout << "The memory address held by stringPTR is: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is: " << &stringREF << std::endl;

    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "The value of s is: " << s << std::endl;
    std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;

    return (0);
}