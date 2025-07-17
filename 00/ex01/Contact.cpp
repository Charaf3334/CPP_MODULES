#include "Contact.hpp"

void	Contact::initFirstName( std::string &fn)
{
	first_name = fn;
}

void	Contact::initLastName( std::string &ln)
{
	last_name = ln;
}

void	Contact::initNickName( std::string &nn)
{
	nick_name = nn;
}

void	Contact::initPhoneNumber( std::string &pn)
{
	phone_number = pn;
}

void	Contact::initDarkestSecret( std::string &ds)
{
	darkest_secret = ds;
}

std::string	Contact::getFirstName() 
{
	return first_name;
}

std::string	Contact::getLastName() 
{
	return last_name;
}

std::string Contact::getNickName() 
{
	return nick_name;
}

std::string Contact::getPhoneNumber() 
{
	return phone_number;
}

std::string Contact::getDarkestSecret() 
{
	return darkest_secret;
}