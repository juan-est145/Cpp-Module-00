/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:07:21 by juestrel          #+#    #+#             */
/*   Updated: 2024/07/28 19:56:16 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook:: ~PhoneBook() {}

void PhoneBook::add(Contact newContact)
{
	static unsigned int index = 0;
	unsigned int size = (unsigned int)(sizeof(contacts) / sizeof(contacts[0]));

	index = index % size;
	contacts[index] = newContact;
	index++;
}