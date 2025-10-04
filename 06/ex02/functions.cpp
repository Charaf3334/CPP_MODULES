#include "functions.hpp"

Base* generate(void)
{
    const int size = 3;
    Base *arr[size] = {new A(), new B(), new C()};
    int i = rand() % size;
    for (int j = 0; j < size; j++)
    {
        if (i == j)
            continue;
        delete arr[j];
    }
    return arr[i];
}

void identify(Base* p)
{
    const int size = 3;
    const std::string arr[size] = {"A", "B", "C"};
    if (dynamic_cast<A*>(p))
        std::cout << arr[0] << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << arr[1] << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << arr[2] << std::endl;
    else
        std::cerr << "Error: Invalid type." << std::endl;
}

void identify(Base& p)
{
    const int size = 3;
    const std::string arr[size] = {"A", "B", "C"};
    try
    {
        A &a_obj = dynamic_cast<A&>(p);
        static_cast<void>(a_obj);
        std::cout << arr[0] << std::endl;
        return; 
    }
    catch(const std::exception &e)
    {

    }
    try
    {
        B &b_obj = dynamic_cast<B&>(p);
        static_cast<void>(b_obj);
        std::cout << arr[1] << std::endl;
        return; 
    }
    catch(const std::exception &e)
    {

    }
    try
    {
        C &c_obj = dynamic_cast<C&>(p);
        static_cast<void>(c_obj);
        std::cout << arr[2] << std::endl;
        return; 
    }
    catch(const std::exception &e)
    {

    }
    std::cerr << "Error: Invalid type." << std::endl;
}
