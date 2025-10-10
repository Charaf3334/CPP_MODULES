#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> stack;

    stack.push(10);
    stack.push(20);

    MutantStack<int>::Iterator it;
    it.iterator = NULL;

    std::cout << *stack.begin() << std::endl;
    std::cout << *(stack.end() - 1) << std::endl;

    while (!stack.empty())
    {
        int n = stack.top();
        stack.pop();
        std::cout << "Elements: " << n << std::endl;
    }
    return 0;
}