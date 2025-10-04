#include "functions.hpp"

int main(void)
{
    srand(time(NULL));

    Base *p = generate();
    Base &x = *p;

    identify(p);
    identify(x);

    delete p;
}