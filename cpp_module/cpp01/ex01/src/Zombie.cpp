/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:53:41 by heha              #+#    #+#             */
/*   Updated: 2022/11/17 11:34:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Zombie.hpp"

// ************************************************************************** //
//                                Internals                                   //
// ************************************************************************** //

enum	_COLOR { _CLR_DEFAULT = 0, _CLR_RED = 31, _CLR_GREEN = 32, _CLR_YELLOW = 33 };
static void	_printConsole(const std::string& name, const char *lpszText, int color = _CLR_DEFAULT)
{
	std::ostringstream	oss;
	oss << name << ": " << "\033[" << color << ";1m" << lpszText << "\033[0m";
	std::cout << oss.str() << std::endl;
}

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Zombie::Zombie()
	: _name()
{}

Zombie::Zombie(const std::string& name)
	: _name(name)
{
	_printConsole(_name, "constructor.", _CLR_YELLOW);
}

Zombie::Zombie(const Zombie& rhs)
	: _name(rhs._name)
{
	_printConsole(_name, "copy constructor.", _CLR_YELLOW);
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

void	Zombie::setName(const std::string& name)	{ _name = name; }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Zombie::announce(void) const
{
	_printConsole(_name, "BraiiiiiiinnnzzzZ...");
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Zombie&	Zombie::operator=(const Zombie& rhs)
{
	_name = rhs._name;
	_printConsole(_name, "copy assignment operator.", _CLR_YELLOW);
	return (*this);
}

Zombie::~Zombie()
{
	_printConsole(_name, "destructor.", _CLR_GREEN);
}
