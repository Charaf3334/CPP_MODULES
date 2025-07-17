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
        Fixed();                                // Default constructor
        Fixed(const int integer);                     // New: int constructor
        Fixed(const float floating);                   // New: float constructor
        Fixed(const Fixed& other);              // Copy constructor
        Fixed& operator=(const Fixed& other);   // Copy assignment
        ~Fixed();                               // Destructor

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;              // New: to float
        int toInt(void) const;                  // New: to int
};

// << operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
