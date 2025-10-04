#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unknown")
{
    throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& theOtherObject) : name(theOtherObject.name)
{
    this->grade = theOtherObject.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& theOtherObject)
{
    if (this != &theOtherObject)
        this->grade = theOtherObject.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() 
{

}

const std::string Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade <= 1)
        throw GradeTooHighException();
    this->grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    this->grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Too low!";
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& b)
{
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return output;
}
