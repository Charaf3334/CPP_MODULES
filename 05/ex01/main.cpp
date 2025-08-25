#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    try
    {
        Bureaucrat b1("B1", 20);
        Form f1("F1", false, 30, 80);
        std::cout << f1 << std::endl;
        f1.beSigned(b1);
        std::cout << f1 << std::endl;
        std::cout << "---------------------------" << std::endl;
        b1.signForm(f1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
