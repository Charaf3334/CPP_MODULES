#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_sign;
        const int grade_execute;
    public:
        Form();
        Form(const Form& theOtherObject);
        Form& operator=(const Form& theOtherObject);
        ~Form();
};

#endif