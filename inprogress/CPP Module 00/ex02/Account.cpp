/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:35:48 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/19 15:30:11 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	if (initial_deposit < 0)
		return ;
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
	this->_accountIndex++;
	this->_nbAccounts++;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_totalAmount << ";";
	std::cout << "closed" << std::endl;
}

/* void	Account::_displayTimestamp( void )
{
	std::time_t	date = time(0);
	std::tm	*timestamp = std::localtime(&date); 
	std::cout << std::put_time(timestamp, "%Y%m%d_%H%M%S ");
} */

void	Account::_displayTimestamp( void )
{
	std::time_t date = std::time(0);
	char timestamp[20];
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S ", std::localtime(&date));
	std::cout << timestamp;
}

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_nbAccounts = getNbAccounts();
	_totalAmount = getTotalAmount();
	_totalNbDeposits = getNbDeposits();
	_totalNbWithdrawals = getNbWithdrawals();
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}


void	Account::makeDeposit( int deposit )
{
	if (deposit < 1)
		return ;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal < 1)
		return (false);
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal; 
		std::cout << "amount:" << this->_amount << ";";
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return(_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
