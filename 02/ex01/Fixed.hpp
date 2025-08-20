#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int number;
        static const int bits = 8;

    public:
        Fixed();
        Fixed(const int integer);
        Fixed(const float floating);
        Fixed(const Fixed &theOtherObject);
        Fixed& operator=(const Fixed &theOtherObject);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};


std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
int myPow(int num, int power);

#endif
