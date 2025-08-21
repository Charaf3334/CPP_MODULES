#include "Point.hpp"

static float myAbs(float number)
{
    if (number < 0)
        return number * -1;
    return number;
}

static float calculate_area(Point const p1, Point const p2, Point const p3)
{
    float x1 = p1.get_x();
    float y1 = p1.get_y();
    float x2 = p2.get_x();
    float y2 = p2.get_y();
    float x3 = p3.get_x();
    float y3 = p3.get_y();

    float n1 = (x1 * y2) + (x2 * y3) + (x3 * y1);
    float n2 = (y1 * x2) + (y2 * x3) + (y3 * x1);

    return (myAbs(n1 - n2)) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float fullArea = calculate_area(a, b, c);
    float PAB = calculate_area(point, a, b);
    float PAC = calculate_area(point, a, c);
    float PBC = calculate_area(point, b, c);

    if (PAB == 0 || PAC == 0 || PBC == 0) // point is vertex
        return false;
    if ((PAB + PAC + PBC) == fullArea)
        return true;
    return false;
}
