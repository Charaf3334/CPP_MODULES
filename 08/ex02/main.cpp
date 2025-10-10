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

    MutantStack<int>::iterator it1 = stack.begin();

    std::cout << "Elements of the stack: " << stack.size() << std::endl;
    while (it1 != stack.end())
    {
        std::cout << *it1 << std::endl;
        it1++;
    }

    std::cout << "Removing elements from the stack..." << std::endl;
    MutantStack<int>::iterator it2 = stack.end() - 1;
    while (it2 != stack.begin() - 1)
    {
        stack.pop();
        it2--;
    }
    std::cout << "Size of the stack: " << stack.size() << std::endl;
    
    return 0;
}