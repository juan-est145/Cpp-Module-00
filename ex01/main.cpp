/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:08:43 by juestrel          #+#    #+#             */
/*   Updated: 2024/07/28 19:29:38 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void greeting()
{
	std::cout << "Welcome to the awesome crappy phonebook. Please, use any the following commands:\n";
	std::cout << "ADD: Add a new contact with the fields first name, last name, nickname, phone number and darkest secret\n";
	std::cout << "SEARCH: Display a specific contact\n";
	std::cout << "EXIT: Quits the program and deletes all contacts\n" << std::endl;
}
std::string getParameter(std::string parameter)
{
	std::string data;
	std::string warning = "Empty inputs are not valid";

	std::cout << "Enter "<< parameter << std::endl;
	do
	{
		std::getline(std::cin, data);
		if (data.empty())
			std::cout << warning << std::endl;
	} while (data.empty());
	return (data);
}

void add(PhoneBook *phoneBook)
{
	std::string firstName = getParameter("first name");
	std::string lastName = getParameter("last name");
	std::string nickName = getParameter("nickname");
	std::string phone = getParameter("phone number");
	std::string secret = getParameter("secret");
	phoneBook->add(Contact(firstName, lastName, nickName, phone, secret));
	std::cout << "Data insertion was successful, please enter another command\n" << std::endl;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string cmd;

	greeting();
	while (std::cin >> cmd, cmd != "EXIT")
	{
		if (cmd == "ADD")
			add(&phoneBook);
		else if (cmd == "SEARCH")
			std::cout << "SEARCH has been called" << std::endl;
		else
			std::cout << "Try again" << std::endl;
	}

	return (0);
}
