#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_sign;
        const int grade_execute;
        int checkGrades(int grade);
    public:
        Form();
        Form(std::string name, bool is_signed, int grade_sign, int grade_execute);
        Form(const Form& theOtherObject);
        Form& operator=(const Form& theOtherObject);
        ~Form();
        const std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeSign(void) const;
        int getGradeExecute(void) const;
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& output, const Form& f);

#endif