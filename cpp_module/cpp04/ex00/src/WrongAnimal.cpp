/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:16:22 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:15:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "WrongAnimal.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

WrongAnimal::WrongAnimal()
	: _type()
{
	_logWrongAnimal(WrongAnimal::_createWrongAnimalLogString("default constructor called"));
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
	: _type(rhs.getType())
{
	_logWrongAnimal(WrongAnimal::_createWrongAnimalLogString("copy constructor called"));
}

WrongAnimal::WrongAnimal(const std::string& type)
	: _type(type)
{
	_logWrongAnimal(WrongAnimal::_createWrongAnimalLogString("constructor called"));
}

WrongAnimal::WrongAnimal(const char *pType)
	: _type(pType)
{
	_logWrongAnimal(WrongAnimal::_createWrongAnimalLogString("constructor called"));
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

const std::string&	WrongAnimal::getType() const	{ return (_type); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	WrongAnimal::makeSound() const
{
	_logWrongAnimal(_createMakeSoundLogString());
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	_logWrongAnimal(WrongAnimal::_createWrongAnimalLogString("copy assignment operator called"));
	if (this != &rhs)
	{
		_type = rhs.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	_logWrongAnimal(WrongAnimal::_createWrongAnimalLogString("destructor called"));
}

void	WrongAnimal::_logWrongAnimal(const std::string& logInfo) const
{
	_logWrongAnimal(logInfo.c_str());
}

void	WrongAnimal::_logWrongAnimal(const char *pLogInfo) const
{
	std::cout << pLogInfo << std::endl;
}

std::string	WrongAnimal::_createWrongAnimalLogString(const std::string& logInfo)
{
	return (WrongAnimal::_createWrongAnimalLogString(logInfo.c_str()));
}

std::string	WrongAnimal::_createWrongAnimalLogString(const char *pLogInfo)
{
	std::ostringstream	oss;
	oss << "WrongAnimal " << pLogInfo;
	return (oss.str());
}

const char	*WrongAnimal::_createMakeSoundLogString() const
{
	return ("WrongAnimals don't have cries");
}
