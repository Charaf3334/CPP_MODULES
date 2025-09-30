#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
    AForm("PresidentialPardonForm", false, 0, 0)
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
    AForm("PresidentialPardonForm", false, 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &theOtherObject) : AForm(theOtherObject)
{
    (void)theOtherObject;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &theOtherObject)
{
    if (this != &theOtherObject)
    {
        (void)theOtherObject;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::executeFormAction() const
{
    std::cout << this->target << " is being pardoned by Zaphod Beeblebrox" << std::endl;
}