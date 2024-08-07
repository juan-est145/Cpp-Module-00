#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
class PhoneBook
{
private:
	Contact contacts[8];
	unsigned int size;
	Contact getNewContact();
	std::string getParameter(std::string parameter);
	void showContacts();
	void printField(std::string contactField);

public:
	PhoneBook();
	~PhoneBook();
	void add();
	void search();
	unsigned int getSize();
};
#endif