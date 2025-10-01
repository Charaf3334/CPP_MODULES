#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
    protected:
        void executeFormAction() const;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &theOtherObject);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &theOtherObject);
        ~RobotomyRequestForm();
};

#endif