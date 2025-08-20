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

    float subtriangle1 = x1 * (y2 - y3);
    float subtriangle2 = x2 * (y3 - y1);
    float subtriangle3 = x3 * (y1 - y2);

    float area = (subtriangle1 + subtriangle2 + subtriangle3) / 2.0f;
    return myAbs(area);
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
