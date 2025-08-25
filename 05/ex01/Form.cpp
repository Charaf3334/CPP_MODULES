#include "Form.hpp"

int Form::checkGrades(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        return grade;
}

Form::Form() : name("Unknown"), is_signed(false), 
    grade_sign(checkGrades(0)),
    grade_execute(checkGrades(0))
{

}

Form::Form(std::string name, bool is_signed, int grade_sign, int grade_execute) 
    : name(name), 
    is_signed(false), 
    grade_sign(checkGrades(grade_sign)), 
    grade_execute(checkGrades(grade_execute))
{
    (void)is_signed;
}

Form::Form(const Form& theOtherObject) : name(theOtherObject.name), 
    is_signed(theOtherObject.is_signed),
    grade_sign(theOtherObject.grade_sign), 
    grade_execute(theOtherObject.grade_execute)
{

}

Form& Form::operator=(const Form& theOtherObject)
{
    if (this != &theOtherObject)
        this->is_signed = theOtherObject.is_signed;
    return *this;
}

Form::~Form()
{
    
}

const std::string Form::getName(void) const
{
    return this->name;
}

bool Form::getIsSigned(void) const
{
    return this->is_signed;
}

int Form::getGradeSign(void) const
{
    return this->grade_sign;
}

int Form::getGradeExecute(void) const
{
    return this->grade_execute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Too low!";
}

std::ostream& operator<<(std::ostream& output, const Form& f)
{
    output << "name: " << f.getName() << ", is_signed: " << f.getIsSigned() 
        << ", grade_sign: " << f.getGradeSign() << ", grade_execute: " << f.getGradeExecute();
    return output;
}

void Form::beSigned(const Bureaucrat& b)
{
    const int bureaucrat_grade = b.getGrade();

    if (bureaucrat_grade <= this->grade_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}
