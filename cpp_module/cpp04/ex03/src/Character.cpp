/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:21:33 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 21:13:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Character.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Character::Character(const std::string& name)
	: _name(name)
{
	_initInventoryArray();
}

Character::Character(const char *pName)
	: _name(pName)
{
	_initInventoryArray();
}

Character::Character(const Character& rhs)
	: _name(rhs.getName())
{
	_copyInventoryArray(rhs);
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

const std::string&	Character::getName() const	{ return(_name); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Character::equip(AMateria *m)
{
	if (m)
	{
		int	findIdx = -1;
		for (int i = 0; i < _NumOfInventory; ++i)
		{
			if (!_inventoryArray[i] && -1 == findIdx)
				findIdx = i;
			else if (_inventoryArray[i] == m)
			{
				findIdx = _NumOfInventory;
				break ;
			}
		}

		if (-1 == findIdx)
			delete m;
		else if (_NumOfInventory != findIdx)
			_inventoryArray[findIdx] = m;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < _NumOfInventory)
	{
		_inventoryArray[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < _NumOfInventory && _inventoryArray[idx])
	{
		_inventoryArray[idx]->use(target);
	}
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		_name = rhs.getName();
		_copyInventoryArray(rhs);
	}
	return (*this);
}

Character::~Character()
{
	_clearInventoryArray();
}

void	Character::_initInventoryArray()
{
	for (int i = 0; i < _NumOfInventory; ++i)
	{
		_inventoryArray[i] = NULL;
	}
}

void	Character::_clearInventoryArray()
{
	for (int i = 0; i < _NumOfInventory; ++i)
	{
		delete _inventoryArray[i];
		_inventoryArray[i] = NULL;
	}
}

void	Character::_copyInventoryArray(const Character& rhs)
{
	for (int i = 0; i < _NumOfInventory; ++i)
	{
		delete _inventoryArray[i];
		_inventoryArray[i] = NULL;
		if (rhs._inventoryArray[i])
			_inventoryArray[i] = rhs._inventoryArray[i]->clone();
	}
}
