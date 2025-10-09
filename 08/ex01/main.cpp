#include "Span.hpp"

int main(void)
{
    srand(time(NULL));
    try
    {
        const unsigned int N = 10; 
        Span s(N);
        s.addNumberRemastered();
        s.print();
        std::cout  << "shortestSpan: " << s.shortestSpan() << std::endl;
        std::cout  << "longestSpan: " << s.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
