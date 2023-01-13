/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:46:42 by heha              #+#    #+#             */
/*   Updated: 2022/12/24 21:28:19 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "ScavTrap.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name, 100, 50, 20)
{
	_logClapTrap(_createScavTrapLogString("constructor called"));
}

ScavTrap::ScavTrap(const char *pName)
	: ClapTrap(pName, 100, 50, 20)
{
	_logClapTrap(_createScavTrapLogString("constructor called"));
}

ScavTrap::ScavTrap(const ScavTrap& rhs)
	: ClapTrap(rhs)
{
	_logClapTrap(_createScavTrapLogString("copy constructor called"));
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	ScavTrap::guardGate()
{
	if (_hitPoints && _energyPoints)
	{
		--_energyPoints;
		_logClapTrap(_createGuardGateLogString());
	}
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_logClapTrap(_createScavTrapLogString("copy assignment operator called"));
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	_logClapTrap(_createScavTrapLogString("destructor called"));
}

std::string	ScavTrap::_createAttackLogString(const std::string& target) const
{
	return (_createAttackLogString(target.c_str()));
}

std::string	ScavTrap::_createAttackLogString(const char *pTarget) const
{
	std::ostringstream	oss;
	oss << "ScavTrap " << _name << " attacks " << pTarget << ", causing " << _attackDamage << " points of damage!" << "(ep: " << _energyPoints << ")";
	return (oss.str());
}

std::string	ScavTrap::_createTakeDamageLogString(unsigned int amount) const
{
	std::ostringstream	oss;
	oss << "ScavTrap " << _name << " takes damage, causing " << amount << " hit points of loses!" << "(hp: " << _hitPoints << ")";
	return (oss.str());
}

std::string	ScavTrap::_createBeRepairedLogString(unsigned int amount) const
{
	std::ostringstream	oss;
	oss << "ScavTrap " << _name << " repairs itself, causing " << amount << " hit points of get!" << "(hp: " << _hitPoints << ", ep: " << _energyPoints << ")";
	return (oss.str());
}

std::string	ScavTrap::_createScavTrapLogString(const std::string& logInfo) const
{
	return (_createScavTrapLogString(logInfo.c_str()));
}

std::string	ScavTrap::_createScavTrapLogString(const char *pLogInfo) const
{
	std::ostringstream	oss;
	oss << "ScavTrap " << _name << ' ' << pLogInfo;
	return (oss.str());
}

std::string	ScavTrap::_createGuardGateLogString() const
{
	std::ostringstream	oss;
	oss << "ScavTrap " << _name << " is now in gate keeper mode!" << "(ep: " << _energyPoints << ")";
	return (oss.str());
}

unsigned int	ScavTrap::_maxHitPoints() const
{
	return (100);
}
