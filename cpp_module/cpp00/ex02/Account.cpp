/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:42:31 by heha              #+#    #+#             */
/*   Updated: 2022/11/17 17:24:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts(0);
int	Account::_totalAmount(0);
int	Account::_totalNbDeposits(0);
int	Account::_totalNbWithdrawals(0);

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Account::Account(int initial_deposit)
	: _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	Account::_totalAmount += _amount;
	++Account::_nbAccounts;
}

Account::Account()
{}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

int	Account::getNbAccounts(void)	{ return (Account::_nbAccounts); }
int	Account::getTotalAmount(void)	{ return (Account::_totalAmount); }
int	Account::getNbDeposits(void)	{ return (Account::_totalNbDeposits); }
int	Account::getNbWithdrawals(void)	{ return (Account::_totalNbWithdrawals); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::ostringstream	oss;
	oss \
		<< "accounts:" << getNbAccounts() \
		<< ";total:" << getTotalAmount() \
		<< ";deposits:" << getNbDeposits() \
		<< ";withdrawals:" << getNbWithdrawals() \
		<< std::flush;
	std::cout << oss.str() << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::ostringstream	oss;
	oss \
		<< "index:" << _accountIndex \
		<< ";amount:" << _amount \
		<< ";deposits:" << _nbDeposits \
		<< ";withdrawals:" << _nbWithdrawals \
		<< std::flush;
	std::cout << oss.str() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	std::ostringstream	oss;
	oss \
		<< "index:" << _accountIndex \
		<< ";p_amount:" << _amount - deposit \
		<< ";deposit:" << deposit \
		<< ";amount:" << _amount \
		<< ";nb_deposits:" << ++_nbDeposits \
		<< std::flush;
	std::cout << oss.str() << std::endl;
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::ostringstream	oss;
	oss \
		<< "index:" << _accountIndex \
		<< ";p_amount:" << _amount \
		<< ";withdrawal:";

	int	oldAmount(_amount);
	_amount -= withdrawal;
	if (checkAmount() < 0)
	{
		oss << "refused" << std::flush;
		std::cout << oss.str() << std::endl;
		_amount = oldAmount;
		return (false);
	}
	else
	{
		oss \
			<< withdrawal \
			<< ";amount:" << _amount \
			<< ";nb_withdrawals:" << ++_nbWithdrawals \
			<< std::flush;
		std::cout << oss.str() << std::endl;
		Account::_totalAmount -= withdrawal;
		++Account::_totalNbWithdrawals;
		return (true);
	}
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	Account::_totalNbWithdrawals -= _nbWithdrawals;
	Account::_totalNbDeposits -= _nbDeposits;
	Account::_totalAmount -= _amount;
	--Account::_nbAccounts;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	t = std::time(NULL);
	std::tm		*now = std::localtime(&t);
	std::ostringstream	oss;
	oss \
		<< std::setfill('0') \
		<< '[' \
		<< std::setw(4) << (now->tm_year + 1900) \
		<< std::setw(2) << (now->tm_mon + 1) \
		<< std::setw(2) << now->tm_mday \
		<< '_' \
		<< std::setw(2) << now->tm_hour \
		<< std::setw(2) << now->tm_min \
		<< std::setw(2) << now->tm_sec \
		<< "] " \
		<< std::flush;
	std::cout << oss.str() << std::flush;
}

int		Account::checkAmount(void) const
{
	return (_amount < 0 ? -1 : 1);
}
