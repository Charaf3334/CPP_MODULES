#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->number = integer << this->bits;
}

Fixed::Fixed(const float floating)
{
    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(floating * (1 << this->bits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->number = other.number;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->number = other.number;
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

float Fixed::toFloat(void) const
{
    int scale = 1 << this->bits;
    float result = (float)this->number / scale;
    return result;
}

int Fixed::toInt(void) const
{
    int result = this->number >> this->bits;
    return result;
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
    float result = fixed.toFloat();
    output << result;
    return output;
}
