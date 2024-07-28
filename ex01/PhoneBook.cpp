/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:07:21 by juestrel          #+#    #+#             */
/*   Updated: 2024/07/28 21:44:05 by juestrel         ###   ########.fr       */
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
		if (data.empty())
			std::cout << warning << std::endl;
	} while (data.empty());
	return (data);
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
	if (contacts[0].getFirstName().length() <= 0)
		std::cout << "There are no contacts yet" << std::endl;
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
