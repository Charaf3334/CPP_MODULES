#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);

    Point p(2, 1);

    bool result = bsp(a, b, c, p);

    if (result)
        std::cout << "The point at (" << p.get_x() << ", " << p.get_y() << ") is inside the triangle!" << std::endl;
    else
        std::cout << "The point at (" << p.get_x() << ", " << p.get_y() << ") is outside the triangle!" << std::endl;

    return (0);
}