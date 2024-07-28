/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:08:43 by juestrel          #+#    #+#             */
/*   Updated: 2024/07/28 19:01:56 by juestrel         ###   ########.fr       */
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

void add(PhoneBook *phoneBook)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phone;
	std::string secret;
	std::string warning = "Empty inputs are not valid";

	std::cout << "Enter first name" << std::endl;
	while (std::cin >> firstName, firstName.length() <= 0)
		std::cout << warning << std::endl;
	std::cout << "Enter last name" << std::endl;
	while (std::cin >> lastName, lastName.length() <= 0)
		std::cout << warning << std::endl;
	std::cout << "Enter nickname" << std::endl;
	while (std::cin >> nickName, nickName.length() <= 0)
		std::cout << warning << std::endl;
	std::cout << "Enter phone" << std::endl;
	while (std::cin >> phone, phone.length() <= 0)
		std::cout << warning << std::endl;
	std::cout << "Enter secret" << std::endl;
	while (std::cin >> secret, secret.length() <= 0)
		std::cout << warning << std::endl;
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
