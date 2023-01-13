/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:45:52 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:13:16 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Animal.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Animal::Animal()
	: _type()
{
	_logAnimal(Animal::_createAnimalLogString("default constructor called"));
}

Animal::Animal(const Animal& rhs)
	: _type(rhs.getType())
{
	_logAnimal(Animal::_createAnimalLogString("copy constructor called"));
}

Animal::Animal(const std::string& type)
	: _type(type)
{
	_logAnimal(Animal::_createAnimalLogString("constructor called"));
}

Animal::Animal(const char *pType)
	: _type(pType)
{
	_logAnimal(Animal::_createAnimalLogString("constructor called"));
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

const std::string&	Animal::getType() const	{ return(_type); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Animal::makeSound() const
{
	_logAnimal(_createMakeSoundLogString());
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Animal&	Animal::operator=(const Animal& rhs)
{
	_logAnimal(Animal::_createAnimalLogString("copy assignment operator called"));
	if (this != &rhs)
	{
		_type = rhs.getType();
	}
	return (*this);
}

Animal::~Animal()
{
	_logAnimal(Animal::_createAnimalLogString("destructor called"));
}

void	Animal::_logAnimal(const std::string& logInfo) const
{
	_logAnimal(logInfo.c_str());
}

void	Animal::_logAnimal(const char *pLogInfo) const
{
	std::cout << pLogInfo << std::endl;
}

std::string	Animal::_createAnimalLogString(const std::string& logInfo)
{
	return (Animal::_createAnimalLogString(logInfo.c_str()));
}

std::string	Animal::_createAnimalLogString(const char *pLogInfo)
{
	std::ostringstream	oss;
	oss << "Animal " << pLogInfo;
	return (oss.str());
}

const char	*Animal::_createMakeSoundLogString() const
{
	return ("Animals don't have cries");
}
