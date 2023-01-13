/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:11:37 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:26:39 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Cat.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Cat::Cat()
	: Animal("Cat"), _brainPtr(NULL)
{
	_logAnimal(Cat::_createCatLogString("constructor called"));
	_brainPtr = new Brain;
	if (!_brainPtr)
		_error("allocation error.");
}

Cat::Cat(const Cat& rhs)
	: Animal(rhs), _brainPtr(NULL)
{
	_logAnimal(Cat::_createCatLogString("copy constructor called"));
	_copyCat(rhs);
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

Brain	*Cat::getBrainPtr() const	{ return (_brainPtr); }

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Cat&	Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);
	_logAnimal(Cat::_createCatLogString("copy assignment operator called"));
	_copyCat(rhs);
	return (*this);
}

Cat::~Cat()
{
	_logAnimal(Cat::_createCatLogString("destructor called"));
	delete _brainPtr;
}

std::string	Cat::_createCatLogString(const std::string& logInfo)
{
	return (Cat::_createCatLogString(logInfo.c_str()));
}

std::string	Cat::_createCatLogString(const char *pLogInfo)
{
	std::ostringstream	oss;
	oss << "Cat " << pLogInfo;
	return (oss.str());
}

const char	*Cat::_createMakeSoundLogString() const
{
	return ("Cat meow~ meow~");
}

void	Cat::_error(const std::string& errorMsg)
{
	_error(errorMsg.c_str());
}

void	Cat::_error(const char *pErrorMsg)
{
	std::ostringstream	oss;
	oss << "\033[31;1mError:\033[0m " << pErrorMsg;
	std::cerr << oss.str() << std::endl;
	delete _brainPtr;
	std::exit(EXIT_FAILURE);
}

void	Cat::_copyCat(const Cat& rhs)
{
	Brain	*pOrig = _brainPtr;
	_brainPtr = new Brain(*rhs.getBrainPtr());
	if (!_brainPtr)
		_error("allocation error.");
	delete pOrig;
}
