/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:59:31 by heha              #+#    #+#             */
/*   Updated: 2022/12/27 16:28:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "DiamondTrap.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name(name)
{
	_logClapTrap(_createDiamondTrapLogString("constructor called"));
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
	: ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs), _name(rhs._name)
{
	_logClapTrap(_createDiamondTrapLogString("copy constructor called"));
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	DiamondTrap::whoAmI()
{
	if (_hitPoints && _energyPoints)
	{
		--_energyPoints;
		_logClapTrap(_createWhoAmILogString());
	}
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		_logClapTrap(_createDiamondTrapLogString("copy assignment operator called"));
		_name = rhs._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	_logClapTrap(_createDiamondTrapLogString("destructor called"));
}

std::string	DiamondTrap::_createAttackLogString(const std::string& target) const
{
	return (_createAttackLogString(target.c_str()));
}

std::string	DiamondTrap::_createAttackLogString(const char *pTarget) const
{
	return (ScavTrap::_createAttackLogString(pTarget));
}

std::string	DiamondTrap::_createTakeDamageLogString(unsigned int amount) const
{
	return (ScavTrap::_createTakeDamageLogString(amount));
}

std::string	DiamondTrap::_createBeRepairedLogString(unsigned int amount) const
{
	return (ScavTrap::_createBeRepairedLogString(amount));
}

std::string	DiamondTrap::_createDiamondTrapLogString(const std::string& logInfo) const
{
	return (_createDiamondTrapLogString(logInfo.c_str()));
}

std::string	DiamondTrap::_createDiamondTrapLogString(const char *pLogInfo) const
{
	std::ostringstream	oss;
	oss << "DiamondTrap " << ClapTrap::_name << ' ' << pLogInfo;
	return (oss.str());
}

std::string	DiamondTrap::_createWhoAmILogString() const
{
	std::ostringstream	oss;
	oss << "DiamondTrap " << ClapTrap::_name << " has another name \"" << _name << "\"!(ep: " << _energyPoints << ")";
	return (oss.str());
}

unsigned int	DiamondTrap::_maxHitPoints() const
{
	return (FragTrap::_maxHitPoints());
}
