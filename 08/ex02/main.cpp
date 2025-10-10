#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> stack;

    int value = 10;
    for (int i = 0; i < 10; i++)
    {
        stack.push(value);
        value += 10;
    }

    MutantStack<int>::iterator it = stack.begin();

    std::cout << "Elements of the stack:" << std::endl;
    while (it != stack.end())
    {
        std::cout << *it << std::endl;
        it++;
    }

    return 0;
}