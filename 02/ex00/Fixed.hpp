#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int number;
        static const int bits = 8;
    public:
        Fixed();                               // Default Constructor
        Fixed(const Fixed& other);             // Copy Constructor
        Fixed& operator=(const Fixed& other);  // Copy Assignment Operator
        ~Fixed();                              // Destructor
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif