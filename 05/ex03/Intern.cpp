#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &theOtherObject)
{
    (void)theOtherObject;
}

Intern& Intern::operator=(const Intern &theOtherObject)
{
    if (this != &theOtherObject)
    {
        (void)theOtherObject;
    }
    return *this;
}

Intern::~Intern()
{

}

AForm* Intern::createPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string &form_name, const std::string &form_target)
{
    const std::string arr[SIZE] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    
    AForm* (Intern::*ptrs[SIZE])(const std::string&) = {&Intern::createPardonForm, &Intern::createRequestForm, &Intern::createCreationForm};

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == form_name)
        {
            std::cout << "Intern creates " << arr[i] << std::endl;
            return (this->*ptrs[i])(form_target);
        }
    }
    std::cerr << "The provided form name doesn't exist." << std::endl;
    return NULL;
}