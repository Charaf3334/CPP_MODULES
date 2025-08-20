#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const Fixed &theOtherObject)
{
    std::cout << "Copy constructor called" << std::endl;
    this->number = theOtherObject.number;
}

Fixed& Fixed::operator=(const Fixed &theOtherObject)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &theOtherObject)
        this->number = theOtherObject.number;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->number; 
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->number = raw;
}