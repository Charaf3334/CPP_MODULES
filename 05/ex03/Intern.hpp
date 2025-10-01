#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define SIZE 3

class Intern
{
    public:
        Intern();
        Intern(const Intern &theOtherObject);
        Intern& operator=(const Intern &theOtherObject);
        ~Intern();
        AForm* makeForm(const std::string &form_name, const std::string &form_target);
        AForm* createPardonForm(const std::string &target);
        AForm* createRequestForm(const std::string &target);
        AForm* createCreationForm(const std::string &target);
};

#endif