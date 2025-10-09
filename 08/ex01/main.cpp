#include "Span.hpp"

int main(void)
{
    try
    {
        const unsigned int N = 10; 
        Span s(N);
        // s.addNumber(5);
        s.addNumberRemastered();
        s.print();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}