#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> stack;

    for (int i = 1; i <= 10; i++)
        stack.push(i * 10);

    MutantStack<int>::iterator it1 = stack.begin();

    std::cout << "Elements of the stack: " << stack.size() << std::endl;
    while (it1 != stack.end())
    {
        std::cout << *it1 << std::endl;
        it1++;
    }

    std::cout << "Removing elements from the stack..." << std::endl;

    while (!stack.empty())
        stack.pop();
    
    std::cout << "Size of the stack: " << stack.size() << std::endl;
    
    return 0;
}