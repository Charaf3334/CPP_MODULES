#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
        Bureaucrat b("Bureacrat", 5);
        ShrubberyCreationForm a("HHHH");
        a.beSigned(b);
        a.execute(b);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
