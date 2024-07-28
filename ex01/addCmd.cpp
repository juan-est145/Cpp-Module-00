/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addCmd.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:36:30 by juestrel          #+#    #+#             */
/*   Updated: 2024/07/28 19:38:08 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void add(PhoneBook *phoneBook)
{
	std::string firstName = getParameter("first name");
	std::string lastName = getParameter("last name");
	std::string nickName = getParameter("nickname");
	std::string phone = getParameter("phone number");
	std::string secret = getParameter("secret");
	phoneBook->add(Contact(firstName, lastName, nickName, phone, secret));
	std::cout << "Data insertion was successful, please enter another command\n"
			  << std::endl;
}

std::string getParameter(std::string parameter)
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
