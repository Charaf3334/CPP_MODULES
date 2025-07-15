#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

static int add_contact(PhoneBook &phonebook)
{
    Contact contact;
    std::string input;

    if (!get_valid_input("First Name: ", input, 1))
        return (0);
    contact.initFirstName(input);

    if (!get_valid_input("Last Name: ", input, 1))
        return (0);
    contact.initLastName(input);

    if (!get_valid_input("Nickname: ", input, 1))
        return (0);
    contact.initNickName(input);

    if (!get_phone_number(input))
        return (0);
    contact.initPhoneNumber(input);

    if (!get_valid_input("Darkest Secret: ", input, 2))
        return (0);
    contact.initDarkestSecret(input);

    phonebook.addContact(contact);
    std::cout << "Contact added succesfully!" << std::endl;
    return (1);
}

static int	search_contact(PhoneBook &phonebook)
{
	if (!phonebook.getContactCount())
	{
		std::cerr << "The Phonebook is empty!" << std::endl;
		return (-1);
	}
	phonebook.displayContacts();
	
	std::string str_index;
	int flag = 0;

	while (1)
	{
		std::cout << (flag == 0 ? "Enter index to view details: " : 
			"Enter a valid index to view details: ");

		if (!std::getline(std::cin, str_index))
			return (0);
	
		if (str_index.length() == 1 && isdigit(str_index[0]))
		{
			if (!phonebook.displayContactDetails(str_index[0] - '0'))
			{
				flag = 1;
				continue ;
			}
			break ;
		}
		else
		{
			flag = 1;
			std::cerr << "Error: Invalid index!" << std::endl;
		}
	}
	return (1);
}

int main(void)
{
	PhoneBook phonebook;
	int	i = 0;
	std::string cmd;

	while (1)
	{
		if (i == 0)
			std::cout << "Welcome to 1337 PhoneBook!" << std::endl;
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			break ;
		}

		if (cmd == "ADD")
		{
			if (!add_contact(phonebook))
			{
				std::cout << std::endl;
				break ;
			}
		}
		else if (cmd == "SEARCH")
		{
			int r = search_contact(phonebook);
			if (!r)
			{
				std::cout << std::endl;
				break ;
			}
			else if (r == -1)
			{
				i++;
				continue;
			}
		}
		else if (cmd == "EXIT")
		{
			std::cout << "Exited .. bye!" << std::endl;
			break ;
		}
		else
			std::cerr << "Error: Invalid command!" << std::endl;
		i++;
	}
	return (0);
}
