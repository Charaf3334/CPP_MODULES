#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	
	public:
		void    initFirstName(const std::string &fn);   
		void    initLastName(const std::string &ln);
		void	initNickName(const std::string &nn);
		void	initPhoneNumber(const std::string &pn);
		void	initDarkestSecret(const std::string &ds);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif