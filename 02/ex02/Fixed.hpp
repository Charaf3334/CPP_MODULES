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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;

		bool operator>(const Fixed &theOtherObject) const;
		bool operator<(const Fixed &theOtherObject) const;
		bool operator>=(const Fixed &theOtherObject) const;
		bool operator<=(const Fixed &theOtherObject) const;
		bool operator==(const Fixed &theOtherObject) const;
		bool operator!=(const Fixed &theOtherObject) const;

		Fixed operator+(const Fixed &theOtherObject) const;
		Fixed operator-(const Fixed &theOtherObject) const;
		Fixed operator*(const Fixed &theOtherObject) const;
		Fixed operator/(const Fixed &theOtherObject) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed& min(Fixed &n1, Fixed &n2);
		static const Fixed& min(const Fixed &n1, const Fixed &n2);
		static Fixed& max(Fixed &n1, Fixed &n2);
		static const Fixed& max(const Fixed &n1, const Fixed &n2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
int myPow(int num, int power);

#endif