/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:35:02 by heha              #+#    #+#             */
/*   Updated: 2023/01/09 12:04:48 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <cstdio>
#include <sstream>
#include <iostream>
#include "PhoneBook.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

PhoneBook::PhoneBook()
	: _contacts(), _countContacts(0U), _appendIdx(0U)
{}

PhoneBook::PhoneBook(const PhoneBook& rhs)
	: _countContacts(rhs._countContacts), _appendIdx(rhs._appendIdx)
{
	for (size_t i = 0U; i < _countContacts; ++i)
		_contacts[i] = rhs._contacts[i];
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

bool	PhoneBook::extract(std::string& cmd)
{
	std::cout << "*****************************************************************" << '\n';
	std::cout << "Please enter the operation of your choice (ADD, EXIT, SEARCH):" << '\n';
	std::cout << "*****************************************************************" << std::endl;
	if (std::getline(std::cin, cmd) && std::cin.eof())
	{
		std::cout << std::endl;
		std::cin.clear();
		clearerr(stdin);
	}

	bool	isEOF(std::cin.eof());
	bool	isExit("EXIT" == cmd);
	if (isEOF)
		std::cout << "\033[32;1m >> EOF!\033[0m" << std::endl;
	else if (isExit)
		std::cout << "\033[32;1m >> Done!\033[0m" << std::endl;
	return (!isEOF && !isExit);
}

void	PhoneBook::perform(const std::string& cmd)
{
	if ("ADD" == cmd)
		_operationAdd();
	else if ("SEARCH" == cmd)
	{
		if (0 < _countContacts)
			_operationSearch();
		else
			std::cout << "\033[33;1m >> Empty contacts. Try again.\033[0m\n";
	}
	else
		std::cout << "\033[33;1m >> Invalid operation input. Try again.\033[0m\n";
	std::cout << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

PhoneBook::~PhoneBook()
{}

PhoneBook&	PhoneBook::operator=(const PhoneBook& rhs)
{
	for (size_t i = 0U; i < _NumOfContacts; ++i)
		_contacts[i] = rhs._contacts[i];
	_countContacts = rhs._countContacts;
	_appendIdx = rhs._appendIdx;
	return (*this);
}

void	PhoneBook::_operationAdd(void)
{
	_contacts[_appendIdx].makeContactInfos();
	if (_countContacts + 1 <= _NumOfContacts)
		++_countContacts;
	if (++_appendIdx >= _NumOfContacts)
		_appendIdx = 0U;
}

void	PhoneBook::_operationSearch(void) const
{
	std::ostringstream	oss;
	oss << "Please enter an index (0";
	if (1 < _countContacts)
		oss << '~' << _countContacts - 1;
	oss << "):" << '\n' << " >> " << std::flush;

	size_t	searchIdx;
	while (true)
	{
		std::cout << oss.str() << std::flush;
		std::cin >> searchIdx;
		if (std::cin.eof())
		{
			clearerr(stdin);
			std::cout << std::endl;
		}

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\033[33;1m >> Invalid index input. Try again.\033[0m" << std::endl;
		}
		else if (searchIdx >= _countContacts)
			std::cout << "\033[33;1m >> Out of range. Try again.\033[0m" << std::endl;
		else
			break ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	_contacts[searchIdx].displayContactInfos(searchIdx);
}
