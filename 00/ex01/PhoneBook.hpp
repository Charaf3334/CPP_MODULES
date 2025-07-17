#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contact_count;
		int oldest_contact;

	public:
		PhoneBook();
		void    addContact( Contact &contact);
		void	displayContacts() ;
		int		displayContactDetails(int index);
		int		getContactCount();
};

std::string ft_trim(std::string str);
int	all_spaces(std::string str);
int	valid_phone_number(std::string phone_number);
int	valid_str(std::string str, int flag);
int get_valid_input( std::string prompt, std::string &out, int flag);
int get_phone_number(std::string &out);

#endif