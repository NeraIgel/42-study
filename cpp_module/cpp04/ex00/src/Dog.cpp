/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:06:06 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:13:50 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Dog.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Dog::Dog()
	: Animal("Dog")
{
	_logAnimal(Dog::_createDogLogString("constructor called"));
}

Dog::Dog(const Dog& rhs)
	: Animal(rhs)
{
	_logAnimal(Dog::_createDogLogString("copy constructor called"));
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		_logAnimal(Dog::_createDogLogString("copy assignment operator called"));
	}
	return (*this);
}

Dog::~Dog()
{
	_logAnimal(Dog::_createDogLogString("destructor called"));
}

std::string	Dog::_createDogLogString(const std::string& logInfo)
{
	return (Dog::_createDogLogString(logInfo.c_str()));
}

std::string	Dog::_createDogLogString(const char *pLogInfo)
{
	std::ostringstream	oss;
	oss << "Dog " << pLogInfo;
	return (oss.str());
}

const char	*Dog::_createMakeSoundLogString() const
{
	return ("Dog bark~ bark~");
}
