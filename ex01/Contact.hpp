#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	Contact(
		std::string firstName,
		std::string lastName,
		std::string nickName,
		std::string phoneNumber,
		std::string darkestSecret);
	~Contact();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
};
#endif