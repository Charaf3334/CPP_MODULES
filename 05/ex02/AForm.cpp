#include "AForm.hpp"

int AForm::checkGrades(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        return grade;
}

AForm::AForm() : name("Unknown"), is_signed(false), 
    grade_sign(checkGrades(0)),
    grade_execute(checkGrades(0))
{

}

AForm::AForm(std::string name, bool is_signed, int grade_sign, int grade_execute) 
    : name(name), 
    is_signed(false), 
    grade_sign(checkGrades(grade_sign)), 
    grade_execute(checkGrades(grade_execute))
{
    (void)is_signed;
}

AForm::AForm(const AForm& theOtherObject) : name(theOtherObject.name), 
    is_signed(theOtherObject.is_signed),
    grade_sign(theOtherObject.grade_sign), 
    grade_execute(theOtherObject.grade_execute)
{

}

AForm& AForm::operator=(const AForm& theOtherObject)
{
    if (this != &theOtherObject)
        this->is_signed = theOtherObject.is_signed;
    return *this;
}

AForm::~AForm()
{
    
}

const std::string AForm::getName(void) const
{
    return this->name;
}

bool AForm::getIsSigned(void) const
{
    return this->is_signed;
}

int AForm::getGradeSign(void) const
{
    return this->grade_sign;
}

int AForm::getGradeExecute(void) const
{
    return this->grade_execute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "The form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << "Form " << f.getName() << " (sign: " << f.getGradeSign() << ", exec: " << f.getGradeExecute() << ", signed: " << (f.getIsSigned() ? "yes" : "no") << ")";
    return out;
}

void AForm::beSigned(const Bureaucrat& b)
{
    const int bureaucrat_grade = b.getGrade();

    if (bureaucrat_grade <= this->grade_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > grade_execute)
        throw GradeTooLowException();
    if (!is_signed)
        throw NotSignedException();
    executeFormAction();
}

