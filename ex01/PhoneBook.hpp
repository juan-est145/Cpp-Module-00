#ifndef PHONEBOOK_HPP
#include "Contact.hpp"
class PhoneBook
{
private:
	Contact contacts[8];

public:
	PhoneBook();
	~PhoneBook();
	void add(Contact newContact);
	void search();
};
#endif