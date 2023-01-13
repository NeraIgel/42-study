/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:24:01 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:15:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "WrongCat.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
	_logWrongAnimal(WrongCat::_createWrongCatLogString("constructor called"));
}

WrongCat::WrongCat(const WrongCat& rhs)
	: WrongAnimal(rhs)
{
	_logWrongAnimal(WrongCat::_createWrongCatLogString("copy constructor called"));
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
	{
		WrongAnimal::operator=(rhs);
		_logWrongAnimal(WrongCat::_createWrongCatLogString("copy assignment operator called"));
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	_logWrongAnimal(WrongCat::_createWrongCatLogString("destructor called"));
}

std::string	WrongCat::_createWrongCatLogString(const std::string& logInfo)
{
	return (WrongCat::_createWrongCatLogString(logInfo.c_str()));
}

std::string	WrongCat::_createWrongCatLogString(const char *pLogInfo)
{
	std::ostringstream	oss;
	oss << "WrongCat " << pLogInfo;
	return (oss.str());
}

const char	*WrongCat::_createMakeSoundLogString() const
{
	return ("WrongCat meow~ meow~");
}
