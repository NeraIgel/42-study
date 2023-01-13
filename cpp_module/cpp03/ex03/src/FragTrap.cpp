/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:52:05 by heha              #+#    #+#             */
/*   Updated: 2022/12/24 21:56:51 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "FragTrap.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name, 100, 100, 30)
{
	_logClapTrap(_createFragTrapLogString("constructor called"));
}

FragTrap::FragTrap(const char *pName)
	: ClapTrap(pName, 100, 100, 30)
{
	_logClapTrap(_createFragTrapLogString("constructor called"));
}

FragTrap::FragTrap(const FragTrap& rhs)
	: ClapTrap(rhs)
{
	_logClapTrap(_createFragTrapLogString("copy constructor called"));
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	FragTrap::highFivesGuys()
{
	if (_hitPoints && _energyPoints)
	{
		--_energyPoints;
		_logClapTrap(_createHighFivesGuysLogString());
	}
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_logClapTrap(_createFragTrapLogString("copy assignment operator called"));
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	_logClapTrap(_createFragTrapLogString("destructor called"));
}

std::string	FragTrap::_createFragTrapLogString(const std::string& logInfo) const
{
	return (_createFragTrapLogString(logInfo.c_str()));
}

std::string	FragTrap::_createFragTrapLogString(const char *pLogInfo) const
{
	std::ostringstream	oss;
	oss << "FragTrap " << _name << ' ' << pLogInfo;
	return (oss.str());
}

std::string	FragTrap::_createHighFivesGuysLogString() const
{
	std::ostringstream	oss;
	oss << "FragTrap " << _name << " requests for a positive high fives!" << "(ep: " << _energyPoints << ")";
	return (oss.str());
}

unsigned int	FragTrap::_maxHitPoints() const
{
	return (100);
}
