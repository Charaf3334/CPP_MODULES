#include "Bureaucrat.hpp"

int main(void)
{
    try 
    {
        Bureaucrat b1("B1", 150);
        b1.decrementGrade();

        Bureaucrat b2("B2", 1);
        b2.incrementGrade();

        std::cout << b1 << std::endl;
        
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
