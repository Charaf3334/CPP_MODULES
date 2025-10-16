#include "RPN.hpp"

RPN::RPN()
{
    throw ("Error: Can't work with empty object.");
}

RPN::RPN(std::string exp)
{
    this->count = this->countParts(exp);
    this->array = this->split(exp);
}

RPN::RPN(const RPN &theOtherObject)
{
    this->myStack = theOtherObject.myStack;
    this->count = theOtherObject.count;
    this->array = new std::string[this->count];
    for (size_t i = 0; i < this->count; i++)
        this->array[i] = theOtherObject.array[i];
}

RPN& RPN::operator=(const RPN &theOtherObject)
{
    if (this != &theOtherObject)
    {
        delete[] this->array;
        this->myStack = theOtherObject.myStack;
        this->count = theOtherObject.count;
        this->array = new std::string[this->count];
        for (size_t i = 0; i < this->count; i++)
            this->array[i] = theOtherObject.array[i];
    }
    return *this;
}

RPN::~RPN()
{
    delete[] this->array;
}

size_t RPN::countParts(const std::string str)
{
    size_t _count = 0;
    bool in_exp = false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
            in_exp = false;
        else
        {
            if (!in_exp)
            {
                _count++;
                in_exp = true;
            }
        }
    }
    return _count;
}

std::string* RPN::split(const std::string str)
{
    std::string* parts = new std::string[this->count];
    size_t size = str.size();

    size_t idx = 0;
    size_t i = 0;
    while (i < size && idx < this->count)
    {
        while (i < size && str[i] == ' ')
            i++;
        if (i >= size)
            break;

        size_t j = i;
        while (j < size && str[j] != ' ') 
            j++;
        parts[idx++] = str.substr(i, j - i);
        i = j;
    }
    return parts;
}

void RPN::executeExpression(void)
{
    this->checkInput();

    for (size_t i = 0; i < this->count; i++)
    {
        char c = this->array[i][0];
        if (isdigit(c))
        {
            int num = atoi(this->array[i].c_str());
            this->myStack.push(num);
        }
        else
        {
            if (c == '+')
                this->calculating('+');
            else if (c == '-')
                this->calculating('-');
            else if (c == '*')
                this->calculating('*');
            else if (c == '/')
                this->calculating('/');
        }
    }
    if (this->myStack.size() == 1)
        std::cout << "Result is: " << this->myStack.top() << std::endl;
    else
        throw std::runtime_error("Error: Two or more operands are still left in the stack.");
}

void RPN::calculating(const char op)
{
    int result = 0;
    if (this->myStack.size() < 2)
        throw std::runtime_error("Error: Not enough operands in the stack.");
    int n1 = this->myStack.top();
    this->myStack.pop();
    int n2 = this->myStack.top();
    this->myStack.pop();
    if (op == '/' && n1 == 0)
        throw std::runtime_error("Error: Can't divide by zero.");
    switch (op)
    {
        case '+':
            result = n2 + n1;
            break;
        case '-':
            result = n2 - n1;
            break;
        case '*':
            result = n2 * n1;
            break;
        case '/':
            result = n2 / n1;
            break;
    }
    this->myStack.push(result);
}

void RPN::checkInput(void) const
{
    if (this->count < 3)
        throw std::runtime_error("Error: Number of elements is not valid.");
    for (size_t i = 0; i < this->count; i++)
    {
        std::string exp = this->array[i];
        if (exp.length() > 1)
            throw std::runtime_error("Error: Length of each element should be 1.");
        char c = exp[0];
        if (i == 0 && (c == '+' || c == '-' || c == '*' || c == '/'))
            throw std::runtime_error("Error: Invalid place of operator.");
        if (c == '+' || c == '-' || c == '*' || c == '/' || isdigit(c))
            continue;
        else
            throw std::runtime_error("Error: Invalid input.");
    }
}
