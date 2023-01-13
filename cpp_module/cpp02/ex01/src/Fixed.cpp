/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:53:51 by heha              #+#    #+#             */
/*   Updated: 2022/12/13 13:07:30 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <sstream>
#include <iostream>
#include "Fixed.hpp"

// ************************************************************************** //
//                                Internals                                   //
// ************************************************************************** //

enum { _CLR_DEFAULT = 0, _CLR_RED = 31, _CLR_GREEN = 32, _CLR_YELLOW = 33 };
static void	_logCall(const char *lpszText, int color = _CLR_DEFAULT)
{
	std::ostringstream	oss;
	oss << "\033[" << color << ";1m" << lpszText << "\033[0m";
	std::cout << oss.str() << std::endl;
}

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Fixed::Fixed()
	: _value(0)
{
	_logCall("Default constructor called", _CLR_YELLOW);
}

Fixed::Fixed(const int n)
	: _value(n << _FractionalBits)
{
	_logCall("Int constructor called", _CLR_YELLOW);
}

Fixed::Fixed(const float n)
	: _value(roundf(n * static_cast<float>(1 << _FractionalBits)))
{
	_logCall("Float constructor called", _CLR_YELLOW);
}

Fixed::Fixed(const Fixed& rhs)
{
	_logCall("Copy constructor called", _CLR_YELLOW);
	*this = rhs;
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

int		Fixed::getRawBits(void) const		{ return (_value); }
void	Fixed::setRawBits(int const raw)	{ _value = raw; }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / (1 << _FractionalBits));
}

int		Fixed::toInt(void) const
{
	return (getRawBits() >> _FractionalBits);
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	_logCall("Copy assignment operator called", _CLR_YELLOW);
	if (this != &rhs)
	{
		_value = rhs.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	_logCall("Destructor called", _CLR_GREEN);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
