/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:51:17 by heha              #+#    #+#             */
/*   Updated: 2022/11/11 16:48:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdio>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Contact.hpp"

// ************************************************************************** //
//                                Internals                                  //
// ************************************************************************** //

static bool	_isNumber(const std::string& s, char delimiter = '-')
{
	std::string::const_iterator	it = s.begin();
	std::string::const_iterator	end = s.end();

	while (it != end && (std::isdigit(*it) || *it == delimiter)) ++it;
	return (!s.empty() && it == end);
}

static void	_setField(const char *lpszText, std::string& str, bool checkNumber = false)
{
	std::ostringstream	oss;
	oss << lpszText << '\n' << " >> " << std::flush;

	while (true)
	{
		std::cout << oss.str() << std::flush;
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cin.clear();
			clearerr(stdin);
		}

		if (str.empty())
			std::cout << "\033[33;1m >> Empty line. Try again.\033[0m" << std::endl;
		else if (checkNumber && !_isNumber(str))
			std::cout << "\033[33;1m >> The input value is not a number. Try again.\033[0m" << std::endl;
		else
			break ;
	}
}

static void	_displayHeader(void)
{
	std::ostringstream	oss;
	oss \
		<< std::right \
		<< std::setw(10) << "index" \
		<< " | " \
		<< std::setw(10) << "first name" \
		<< " | " \
		<< std::setw(10) << "last name" \
		<< " | " \
		<< std::setw(10) << "nickname" \
		<< std::flush;
	std::cout << oss.str() << std::endl;
}

static void	_displayIndex(size_t n, const char *postfix = "")
{
	std::ostringstream	oss;
	oss << std::right << std::setw(10) << n << postfix << std::flush;
	std::cout << oss.str();
}

static void	_displayField(const std::string& str, const char *postfix = "")
{
	std::ostringstream	oss;
	oss << std::right;
	if (10 < str.length())
		oss << std::setw(9) << str.substr(0, 9) << '.';
	else
		oss << std::setw(10) << str;
	oss << postfix << std::flush;
	std::cout << oss.str();
}

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Contact::Contact()
	: _firstName(), _lastName(), _nickname(), _phoneNumber(), _darkestSecret()
{}

Contact::Contact(const Contact& rhs)
	: _firstName(rhs._firstName), _lastName(rhs._lastName), _nickname(rhs._nickname), _phoneNumber(rhs._phoneNumber), _darkestSecret(rhs._darkestSecret)
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Contact::makeContactInfos(void)
{
	_clearContactInfos();
	_setField("Please enter your first name: ", _firstName);
	_setField("Please enter your last name: ", _lastName);
	_setField("Please enter your nickname: ", _nickname);
	_setField("Please enter your phone number: ", _phoneNumber, true);
	_setField("Please enter your darkest secret: ", _darkestSecret);
}

void	Contact::displayContactInfos(size_t displayIndex) const
{
	_displayHeader();
	_displayIndex(displayIndex, " | ");
	_displayField(_firstName, " | ");
	_displayField(_lastName, " | ");
	_displayField(_nickname);
	std::cout << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Contact::~Contact()
{}

Contact&	Contact::operator=(const Contact& rhs)
{
	_firstName = rhs._firstName;
	_lastName = rhs._lastName;
	_nickname = rhs._nickname;
	_phoneNumber = rhs._phoneNumber;
	_darkestSecret = rhs._darkestSecret;
	return (*this);
}

void	Contact::_clearContactInfos(void)
{
	_firstName.clear();
	_lastName.clear();
	_nickname.clear();
	_phoneNumber.clear();
	_darkestSecret.clear();
}
