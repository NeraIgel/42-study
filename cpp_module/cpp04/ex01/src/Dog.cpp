/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:06:06 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:24:07 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Dog.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Dog::Dog()
	: Animal("Dog"), _brainPtr(NULL)
{
	_logAnimal(Dog::_createDogLogString("constructor called"));
	_brainPtr = new Brain;
	if (!_brainPtr)
		_error("allocation error.");
}

Dog::Dog(const Dog& rhs)
	: Animal(rhs), _brainPtr(NULL)
{
	_logAnimal(Dog::_createDogLogString("copy constructor called"));
	_copyDog(rhs);
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

Brain	*Dog::getBrainPtr() const	{ return (_brainPtr); }

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Dog&	Dog::operator=(const Dog& rhs)
{
	Animal::operator=(rhs);
	_logAnimal(Dog::_createDogLogString("copy assignment operator called"));
	_copyDog(rhs);
	return (*this);
}

Dog::~Dog()
{
	_logAnimal(Dog::_createDogLogString("destructor called"));
	delete _brainPtr;
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

void	Dog::_error(const std::string& errorMsg)
{
	_error(errorMsg.c_str());
}

void	Dog::_error(const char *pErrorMsg)
{
	std::ostringstream	oss;
	oss << "\033[31;1mError:\033[0m " << pErrorMsg;
	std::cerr << oss.str() << std::endl;
	delete _brainPtr;
	std::exit(EXIT_FAILURE);
}

void	Dog::_copyDog(const Dog& rhs)
{
	Brain	*pOrig = _brainPtr;
	_brainPtr = new Brain(*rhs.getBrainPtr());
	if (!_brainPtr)
		_error("allocation error.");
	delete pOrig;
}
