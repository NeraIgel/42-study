/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:14:21 by heha              #+#    #+#             */
/*   Updated: 2022/12/24 21:37:50 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "ClapTrap.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	_logClapTrap(_createClapTrapLogString("constructor called"));
}

ClapTrap::ClapTrap(const char *pName)
	: _name(pName), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	_logClapTrap(_createClapTrapLogString("constructor called"));
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
	: _name(rhs._name), _hitPoints(rhs._hitPoints), _energyPoints(rhs._energyPoints), _attackDamage(rhs._attackDamage)
{
	_logClapTrap(_createClapTrapLogString("copy constructor called"));
}

ClapTrap::ClapTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int damage)
	: _name(name), _hitPoints(hp), _energyPoints(ep), _attackDamage(damage)
{
	_logClapTrap(_createClapTrapLogString("constructor called"));
}

ClapTrap::ClapTrap(const char *pName, unsigned int hp, unsigned int ep, unsigned int damage)
	: _name(pName), _hitPoints(hp), _energyPoints(ep), _attackDamage(damage)
{
	_logClapTrap(_createClapTrapLogString("constructor called"));
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	ClapTrap::attack(const std::string& target)
{
	attack(target.c_str());
}

void	ClapTrap::attack(const char *pTarget)
{
	if (_hitPoints && _energyPoints)
	{
		--_energyPoints;
		_logClapTrap(_createAttackLogString(pTarget));
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints && amount)
	{
		_hitPoints = (_hitPoints > amount) ? _hitPoints - amount : 0;
		_logClapTrap(_createTakeDamageLogString(amount));
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints && _hitPoints < _maxHitPoints() && _energyPoints)
	{
		unsigned int	repairAmount;
		if (amount > _maxHitPoints())
			repairAmount = _maxHitPoints() - _hitPoints;
		else
			repairAmount = (_hitPoints + amount > _maxHitPoints()) ? _maxHitPoints() - _hitPoints : amount;
		_hitPoints += repairAmount;
		--_energyPoints;
		_logClapTrap(_createBeRepairedLogString(amount));
	}
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	_logClapTrap(_createClapTrapLogString("copy assignment operator called"));
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	_logClapTrap(_createClapTrapLogString("destructor called"));
}

std::string	ClapTrap::_createAttackLogString(const std::string& target) const
{
	return (_createAttackLogString(target.c_str()));
}

std::string	ClapTrap::_createAttackLogString(const char *pTarget) const
{
	std::ostringstream	oss;
	oss << "ClapTrap " << _name << " attacks " << pTarget << ", causing " << _attackDamage << " points of damage!" << "(ep: " << _energyPoints << ")";
	return (oss.str());
}

std::string	ClapTrap::_createTakeDamageLogString(unsigned int amount) const
{
	std::ostringstream	oss;
	oss << "ClapTrap " << _name << " takes damage, causing " << amount << " hit points of loses!" << "(hp: " << _hitPoints << ")";
	return (oss.str());
}

std::string	ClapTrap::_createBeRepairedLogString(unsigned int amount) const
{
	std::ostringstream	oss;
	oss << "ClapTrap " << _name << " repairs itself, causing " << amount << " hit points of get!" << "(hp: " << _hitPoints << ", ep: " << _energyPoints << ")";
	return (oss.str());
}

std::string	ClapTrap::_createClapTrapLogString(const std::string& logInfo) const
{
	return (_createClapTrapLogString(logInfo.c_str()));
}

std::string	ClapTrap::_createClapTrapLogString(const char *pLogInfo) const
{
	std::ostringstream	oss;
	oss << "ClapTrap " << _name << ' ' << pLogInfo;
	return (oss.str());
}

unsigned int	ClapTrap::_maxHitPoints() const
{
	return (10);
}

void	ClapTrap::_logClapTrap(const std::string& logInfo) const
{
	_logClapTrap(logInfo.c_str());
}

void	ClapTrap::_logClapTrap(const char *pLogInfo) const
{
	std::cout << pLogInfo << std::endl;
}
