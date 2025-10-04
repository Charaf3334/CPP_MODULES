#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", false, 0, 0)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
    AForm("ShrubberyCreationForm", false, 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &theOtherObject) : AForm(theOtherObject)
{
    (void)theOtherObject;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &theOtherObject)
{
    if (this != &theOtherObject)
    {
        AForm::operator=(theOtherObject);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::executeFormAction() const
{
    std::ofstream file((this->target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: failed to open the file: " << this->target + "_shrubbery" << std::endl;
        return;
    }
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\" << std::endl;
    file.close();
}