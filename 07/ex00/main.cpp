#include "whatever.hpp"

int main(void)
{
    int a = 10;
    int b = 20;

    std::cout << "Before:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "--------" << std::endl;

    swap(a, b);

    std::cout << "After:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "--------" << std::endl;

    std::cout << "Min value between " << a << " and " << b << " is: " << min(a, b) << std::endl;
    std::cout << "Max value between " << a << " and " << b << " is: " << min(a, b) << std::endl;

    return 0;
}