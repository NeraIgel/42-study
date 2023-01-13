/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:25:25 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 17:09:05 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include "MateriaSource.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

MateriaSource::MateriaSource()
{
	_initMateriaArray();
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	_copyMateriaArray(rhs);
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m)
	{
		for (int i = 0; i < _NumOfMateria; ++i)
		{
			if (!_materiaArray[i])
			{
				_materiaArray[i] = m->clone();
				break ;
			}
		}
		delete m;
	}
}

AMateria	*MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < _NumOfMateria && _materiaArray[i]; ++i)
	{
		if (type == _materiaArray[i]->getType())
		{
			return (_materiaArray[i]->clone());
		}
	}
	return (NULL);
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		_copyMateriaArray(rhs);
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	_clearMateriaArray();
}

void	MateriaSource::_initMateriaArray()
{
	for (int i = 0; i < _NumOfMateria; ++i)
	{
		_materiaArray[i] = NULL;
	}
}

void	MateriaSource::_clearMateriaArray()
{
	for (int i = 0; i < _NumOfMateria; ++i)
	{
		delete _materiaArray[i];
		_materiaArray[i] = NULL;
	}
}

void	MateriaSource::_copyMateriaArray(const MateriaSource& rhs)
{
	for (int i = 0; i < _NumOfMateria; ++i)
	{
		delete _materiaArray[i];
		_materiaArray[i] = NULL;
		if (rhs._materiaArray[i])
			_materiaArray[i] = rhs._materiaArray[i]->clone();
	}
}
