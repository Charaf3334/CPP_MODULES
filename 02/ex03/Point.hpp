#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &theOtherObject);
        Point& operator=(const Point &theOtherObject);
        ~Point();
        float get_x(void) const;
        float get_y(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif