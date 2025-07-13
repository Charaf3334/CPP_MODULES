#include "Contact.hpp"

void	Contact::initFirstName(const std::string &fn)
{
	first_name = fn;
}

void	Contact::initLastName(const std::string &ln)
{
	last_name = ln;
}

void	Contact::initNickName(const std::string &nn)
{
	nick_name = nn;
}

void	Contact::initPhoneNumber(const std::string &pn)
{
	phone_number = pn;
}

void	Contact::initDarkestSecret(const std::string &ds)
{
	darkest_secret = ds;
}

std::string	Contact::getFirstName() const
{
	return first_name;
}

std::string	Contact::getLastName() const
{
	return last_name;
}

std::string Contact::getNickName() const
{
	return nick_name;
}

std::string Contact::getPhoneNumber() const
{
	return phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return darkest_secret;
}