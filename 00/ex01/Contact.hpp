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
		void    initFirstName( std::string &fn);   
		void    initLastName( std::string &ln);
		void	initNickName( std::string &nn);
		void	initPhoneNumber( std::string &pn);
		void	initDarkestSecret( std::string &ds);

		std::string getFirstName() ;
		std::string getLastName() ;
		std::string getNickName() ;
		std::string getPhoneNumber() ;
		std::string getDarkestSecret() ;
};

#endif