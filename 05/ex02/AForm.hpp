#ifndef AAFORM_HPP
#define AAFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_sign;
        const int grade_execute;
        int checkGrades(int grade);
    protected:
        virtual void executeFormAction() const = 0;
    public:
        AForm();
        AForm(std::string name, bool is_signed, int grade_sign, int grade_execute);
        AForm(const AForm& theOtherObject);
        AForm& operator=(const AForm& theOtherObject);
        virtual ~AForm();
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
        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream& output, const AForm& f);

#endif