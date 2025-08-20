#include "Point.hpp"

Point::Point() : x(0), y(0) {

}

Point::Point(const float x, const float y) : x(x), y(y) {

}

Point::Point(const Point &theOtherObject) : x(theOtherObject.x), y(theOtherObject.y) {

}

Point& Point::operator=(const Point &theOtherObject)
{
    (void)theOtherObject;
    
    return *this;
}

Point::~Point() {

}

float Point::get_x(void) const
{
    return x.toFloat();
}

float Point::get_y(void) const
{
    return y.toFloat();
}