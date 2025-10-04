#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
    AForm("RobotomyRequestForm", false, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
    AForm("RobotomyRequestForm", false, 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &theOtherObject) : AForm(theOtherObject)
{
    (void)theOtherObject;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &theOtherObject)
{
    if (this != &theOtherObject)
    {
        AForm::operator=(theOtherObject);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::executeFormAction() const
{
    srand(time(NULL));
    std::cout << "Noises ...." << std::endl;
    int yes = (std::rand() % 2);
    if (yes)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "robotomization failed on " << this->target << std::endl;
}