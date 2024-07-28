/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:08:43 by juestrel          #+#    #+#             */
/*   Updated: 2024/07/28 20:35:14 by juestrel         ###   ########.fr       */
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
