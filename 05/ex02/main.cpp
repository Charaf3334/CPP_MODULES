#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
        Bureaucrat b("Bureaucrat", 5);
        RobotomyRequestForm a("randomGuy");
        a.beSigned(b);
        b.executeForm(a);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
