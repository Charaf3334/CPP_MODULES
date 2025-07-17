#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

int PhoneBook::getContactCount()
{
	return contact_count;
}

PhoneBook::PhoneBook()
{
	contact_count = 0;
	oldest_contact = 0;
}

void	PhoneBook::addContact( Contact &contact)
{
	contacts[oldest_contact] = contact;
	oldest_contact = (oldest_contact + 1) % 8;
	if (contact_count < 8)
		contact_count++;
}

static	std::string formatField( std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::displayContacts() 
{
	std::cout << std::setw(10) << "Index" << "|" 
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < contact_count; i++)
	{
		std::string fn = contacts[i].getFirstName();
		std::string ln = contacts[i].getLastName();
		std::string nn = contacts[i].getNickName();

		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << formatField(fn) << "|"
			<< std::setw(10) << formatField(ln) << "|"
			<< std::setw(10) << formatField(nn) << std::endl;
	}
}

int	PhoneBook::displayContactDetails(int index)
{

	
	if (index < 0 || index >= contact_count)
	{
		std::cout << "Error: Invalid index!" << std::endl;
		return (0);
	}

	Contact &c = contacts[index];

	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickName() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
	return (1);
}