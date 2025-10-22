#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <limits>
#include <cctype>

class RPN
{
	private:
		std::stack<double> myStack;
		std::string *array;
		size_t count;
		
		size_t countParts(const std::string str);
		std::string* split(const std::string str);
		void checkInput(void) const;
		void calculating(const char op);
		bool isInfinity(const double number) const;
	public:
		RPN();
		RPN(std::string exp);
		RPN(const RPN &theOtherObject);
		RPN& operator=(const RPN &theOtherObject);
		~RPN();
		void executeExpression(void);
};

#endif