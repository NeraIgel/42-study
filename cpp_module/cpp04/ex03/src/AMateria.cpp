/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:12:15 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 16:53:17 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include "AMateria.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

AMateria::AMateria()
	: _type()
{}

AMateria::AMateria(const std::string& type)
	: _type(type)
{}

AMateria::AMateria(const char *pType)
	: _type(pType)
{}

AMateria::AMateria(const AMateria& rhs)
	: _type()
{
	(void)rhs;
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

const std::string&	AMateria::getType() const	{ return(_type); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	AMateria::use(ICharacter& target)
{
	std::ostringstream	oss;
	oss << "* It makes no sense to use AMateria. It does nothing for the " << target.getName() << " *";
	std::cout << oss.str() << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	(void)rhs;
	return (*this);
}

AMateria::~AMateria()
{}

void	AMateria::_error(const std::string& errorMsg)
{
	AMateria::_error(errorMsg.c_str());
}

void	AMateria::_error(const char *pErrorMsg)
{
	std::ostringstream	oss;
	oss << "\033[31;1mError:\033[0m " << pErrorMsg;
	std::cerr << oss.str() << std::endl;
	std::exit(EXIT_FAILURE);
}
