/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:11:37 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:14:31 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Cat.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Cat::Cat()
	: Animal("Cat")
{
	_logAnimal(Cat::_createCatLogString("constructor called"));
}

Cat::Cat(const Cat& rhs)
	: Animal(rhs)
{
	_logAnimal(Cat::_createCatLogString("copy constructor called"));
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		_logAnimal(Cat::_createCatLogString("copy assignment operator called"));
	}
	return (*this);
}

Cat::~Cat()
{
	_logAnimal(Cat::_createCatLogString("destructor called"));
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
