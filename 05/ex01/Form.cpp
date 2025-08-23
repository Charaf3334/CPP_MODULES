#include "Form.hpp"

Form::Form() : name("Unknown"), is_signed(0), grade_sign(0), grade_execute(0)
{

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
