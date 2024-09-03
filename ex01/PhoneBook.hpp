#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstdlib>
# include <iostream>
# include <sstream>
# include <string>
# include "Contact.hpp"
# include "main.hpp"

class PhoneBook
{
  private:
	Contact contacts[8];
	unsigned int size;
	Contact getNewContact();
	std::string getParameter(std::string parameter);
	void showContacts();
	void printField(std::string contactField);
	bool validPhone(std::string phone);

  public:
	PhoneBook();
	~PhoneBook();
	void add();
	void search();
	unsigned int getSize();
};
#endif