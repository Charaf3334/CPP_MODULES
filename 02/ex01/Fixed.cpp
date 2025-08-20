#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->number = integer * myPow(2, this->bits);
}

Fixed::Fixed(const float floating)
{
    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(floating * myPow(2, this->bits));
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

float Fixed::toFloat(void) const
{
    float result = (float)this->number / myPow(2, this->bits);
    return result;
}

int Fixed::toInt(void) const
{
    int result = this->number / myPow(2, this->bits);
    return result;
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
    float result = fixed.toFloat();
    output << result;
    return output;
}

int myPow(int num, int power)
{
    int result;

    if (power < 0)
        return 0;
    if (!power)
        return 1;
    if (power == 1)
        return num;
    result = num;
    for (int i = 2; i <= power; i++)
        result = result * num;
    return result;
}