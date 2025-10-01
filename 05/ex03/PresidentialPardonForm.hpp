#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
    protected:
        void executeFormAction() const;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &theOtherObject);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &theOtherObject);
        ~PresidentialPardonForm();
};

#endif