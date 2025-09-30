#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;
    protected:
        void executeFormAction() const;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &theOtherObject);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &theOtherObject);
        ~ShrubberyCreationForm();

};

#endif