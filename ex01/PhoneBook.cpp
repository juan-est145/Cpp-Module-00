/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:07:21 by juestrel          #+#    #+#             */
/*   Updated: 2024/09/02 18:11:03 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = (unsigned int)(sizeof(contacts) / sizeof(contacts[0]));
}

PhoneBook::~PhoneBook() {}

Contact PhoneBook::getNewContact()
{
	std::string firstName = this->getParameter("first name");
	std::string lastName = this->getParameter("last name");
	std::string nickName = this->getParameter("nickname");
	std::string phone = this->getParameter("phone number");
	std::string secret = this->getParameter("secret");
	Contact newContact(firstName, lastName, nickName, phone, secret);
	std::cout << "Data insertion was successful, please enter another command\n"
			  << std::endl;
	return (newContact);
}

std::string PhoneBook::getParameter(std::string parameter)
{
	std::string data;
	std::string warning = "Empty inputs are not valid";

	std::cout << "Enter " << parameter << std::endl;
	do
	{
		std::getline(std::cin, data);
		if (data.empty() && !std::cin.eof())
			std::cout << warning << std::endl;
		else if (std::cin.eof())
			exitMessage();
	} while (data.empty());
	return (data);
}

void PhoneBook::showContacts()
{
	for (unsigned int i = 0; i < size; i++)
	{
		if (contacts[i].getFirstName().length() <= 0)
			break;
		std::ostringstream numberStr;
		numberStr << i;
		this->printField(numberStr.str());
		this->printField(contacts[i].getFirstName());
		this->printField(contacts[i].getLastName());
		this->printField(contacts[i].getNickName());
		std::cout << std::endl;
	}
}

void PhoneBook::printField(std::string contactField)
{
	unsigned int columnSpace = contactField.length() >= 10 ? 0 : 10 - contactField.length();
	std::cout << "|";
	for (unsigned int i = 0; i < columnSpace; i++)
		std::cout << " ";
	std::cout << contactField.substr(0, 9);
	if (columnSpace == 0)
		std::cout << ".";
	std::cout << "|";
}

void PhoneBook::add()
{
	static unsigned int index = 0;
	Contact newContact = this->getNewContact();

	index = index % size;
	contacts[index] = newContact;
	index++;
}

void PhoneBook::search()
{
	std::string indexSelect;
	bool breakLoop = false;
	unsigned int number;
	
	if (contacts[0].getFirstName().length() <= 0)
	{
		std::cout << "There are no contacts yet" << std::endl;
		return;
	}
	this->showContacts();
	std::cout << "Select the index for the contact you want to see all the information of" << std::endl;
	while (!breakLoop)
	{
		std::getline(std::cin, indexSelect);
		number = (unsigned int)atoi(indexSelect.c_str());
		if ((number == 0 && indexSelect[0] != '0') || number >= this->getSize() || contacts[number].getFirstName().length() <= 0)
			std::cout<< "Invalid index, select any of the previously shown indexes" << std::endl;
		else
			breakLoop = true;
	}
	std::cout << contacts[number].getFirstName() << '\n';
	std::cout << contacts[number].getLastName() << '\n';
	std::cout << contacts[number].getNickName() << '\n';
	std::cout << contacts[number].getPhoneNumber() << '\n';
	std::cout << contacts[number].getDarkestSecret() << std::endl;
}

unsigned int PhoneBook::getSize()
{
	return (this->size);
}
