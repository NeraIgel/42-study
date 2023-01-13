/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:16:49 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 16:57:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Cure.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Cure::Cure()
	: AMateria("cure")
{}

Cure::Cure(const Cure& rhs)
	: AMateria(rhs)
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

AMateria	*Cure::clone() const
{
	AMateria	*pa = new Cure();
	if (!pa)
		AMateria::_error("Cure allocation error.");
	return (pa);
}

void	Cure::use(ICharacter& target)
{
	std::ostringstream	oss;
	oss << "* heals " << target.getName() << "'s wounds *";
	std::cout << oss.str() << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Cure&	Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return (*this);
}

Cure::~Cure()
{}
