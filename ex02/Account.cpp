/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:48:14 by juestrel          #+#    #+#             */
/*   Updated: 2024/07/29 20:51:26 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
			  << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() 
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit
			  << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:"
			  << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->_amount < withdrawal)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
				  << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal
			  << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:"
			  << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t time;
	char buffer[16];

	std::time(&time);
	std::tm *localTimeStruct = std::localtime(&time);
	std::strftime(buffer, 16, "%Y%m%d_%H%M%S", localTimeStruct);
	std::cout << '[' << buffer << "] ";
}
