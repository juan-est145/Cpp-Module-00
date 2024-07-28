#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <string>
#include <iostream>
class PhoneBook
{
private:
	Contact contacts[8];
	Contact getNewContact();
	std::string getParameter(std::string parameter);

public:
	PhoneBook();
	~PhoneBook();
	void add();
	void search();
};
#endif