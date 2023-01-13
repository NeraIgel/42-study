/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:19:45 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 15:40:46 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Ice.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Ice::Ice()
	: AMateria("ice")
{}

Ice::Ice(const Ice& rhs)
	: AMateria(rhs)
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

AMateria	*Ice::clone() const
{
	AMateria	*pa = new Ice();
	if (!pa)
		AMateria::_error("Ice allocation error.");
	return (pa);
}

void	Ice::use(ICharacter& target)
{
	std::ostringstream	oss;
	oss << "* shoots an ice bolt at " << target.getName() << " *";
	std::cout << oss.str() << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Ice&	Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return (*this);
}

Ice::~Ice()
{}
