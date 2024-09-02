/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:08:43 by juestrel          #+#    #+#             */
/*   Updated: 2024/09/02 17:59:16 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string cmd;

	greeting();
	while (std::getline(std::cin, cmd), cmd != "EXIT")
	{
		if (cmd == "ADD")
			phoneBook.add();
		else if (cmd == "SEARCH")
			phoneBook.search();
		else if (std::cin.eof())
			exitMessage();
		else
			std::cout << "Try again" << std::endl;
	}

	return (0);
}

void greeting()
{
	std::cout << "Welcome to the awesome crappy phonebook. Please, use any the following commands:\n";
	std::cout << "ADD: Add a new contact with the fields first name, last name, nickname, phone number and darkest secret\n";
	std::cout << "SEARCH: Display a specific contact\n";
	std::cout << "EXIT: Quits the program and deletes all contacts\n"
			  << std::endl;
}

void exitMessage()
{
	std::cout << "The standard input was closed, exiting program\n";
	exit(0);
}
