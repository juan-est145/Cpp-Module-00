/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:08:43 by juestrel          #+#    #+#             */
/*   Updated: 2024/07/28 18:27:21 by juestrel         ###   ########.fr       */
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
	std::cout << "EXIT: Quits the program and deletes all contacts" << std::endl;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string cmd;
	
	greeting();
	while (std::cin >> cmd, cmd != "EXIT")
	{
		if (cmd == "ADD")
			std::cout << "ADD has been called" << std::endl;
		else if (cmd == "SEARCH")
			std::cout << "SEARCH has been called" << std::endl;
		else
			std::cout << "Try again" << std::endl;
	}
	
	return (0);
}
