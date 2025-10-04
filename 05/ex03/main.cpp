#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
    AForm* rrf = NULL;
    try
    {
        Bureaucrat b("Bureacrat", 5);
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
        if (!rrf)
            return 1;
        rrf->beSigned(b);
        rrf->execute(b);
        if (rrf)
        {
            delete rrf;
            rrf = NULL;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        if (rrf)
            delete rrf;
        return 1;
    }
    return 0;
}
