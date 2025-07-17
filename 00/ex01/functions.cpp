#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

std::string ft_trim(std::string str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < str.length())
	{
		if (!std::isspace(str[start]))
			break ;
		start++;
	}
	while (end > start)
	{
		if (!std::isspace(str[end - 1]))
			break ;
		end--;
	}
	return (str.substr(start, end - start));
}

int	all_spaces(std::string str)
{
	size_t	i = 0;
	size_t	length = str.length();

	while (i < length && std::isspace(str[i]))
		i++;
	if (i == length)
		return (1);
	return (0);
}

int	valid_phone_number(std::string phone_number)
{
	size_t	length = phone_number.length();
	size_t i;

	if (phone_number[0] != '+' && length != 10)
		return (0);
	else if (phone_number[0] == '+' && length != 13)
		return (0);
	phone_number[0] == '+' ? i = 1 : i = 0;
	while (i < length)
	{
		if (!isdigit(phone_number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_str(std::string str, int flag)
{
	int length = str.length();

	if (flag == 1)
	{
		for (int i = 0; i < length; i++)
		{
			if (!isalpha(str[i]))
				return (0);
		}
		return (1);
	}
	else if (flag == 2)
	{
		for (int i = 0; i < length; i++)
		{
			if (!isalnum(str[i]) && str[i] != ' ')
				return (0);
		}
		return (1);
	}
	return (1);
}

int get_valid_input( std::string prompt, std::string &out, int flag)
{
    std::string input;
    while (1)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return 0;
        
        input = ft_trim(input);
        if (all_spaces(input) || !valid_str(input, flag))
            std::cerr << "Error: Not a valid input!" << std::endl;
        else
        {
            out = input;
            return 1;
        }
    }
}

int get_phone_number(std::string &out)
{
    std::string input;

    while (1)
    {
        std::cout << "Phone Number: ";
        if (!std::getline(std::cin, input))
            return 0;
        
        input = ft_trim(input);
        if (all_spaces(input))
        {
            std::cerr << "Error: Not a valid input!" << std::endl;
            continue ;
        }
        if (valid_phone_number(input))
        {
            out = input;
            return 1;
        }
        else
            std::cerr << "Error: Not a valid phone number!" << std::endl;
    }
}
