/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:53:51 by heha              #+#    #+#             */
/*   Updated: 2022/12/14 12:17:42 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Fixed::Fixed()
	: _value(0)
{}

Fixed::Fixed(const int n)
	: _value(n << _FractionalBits)
{}

Fixed::Fixed(const float n)
	: _value(roundf(n * static_cast<float>(1 << _FractionalBits)))
{}

Fixed::Fixed(const Fixed& rhs)
{
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
	if (this != &rhs)
	{
		_value = rhs.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& rhs) const	{ return(getRawBits() > rhs.getRawBits()); }
bool	Fixed::operator<(const Fixed& rhs) const	{ return(rhs > *this); }
bool	Fixed::operator>=(const Fixed& rhs) const	{ return(!(*this < rhs)); }
bool	Fixed::operator<=(const Fixed& rhs) const	{ return(!(*this > rhs)); }
bool	Fixed::operator==(const Fixed& rhs) const	{ return(getRawBits() == rhs.getRawBits()); }
bool	Fixed::operator!=(const Fixed& rhs) const	{ return(!(*this == rhs)); }

const Fixed	Fixed::operator+(const Fixed& rhs) const	{ return (Fixed(toFloat() + rhs.toFloat())); }
const Fixed	Fixed::operator-(const Fixed& rhs) const	{ return (Fixed(toFloat() - rhs.toFloat())); }
const Fixed	Fixed::operator*(const Fixed& rhs) const	{ return (Fixed(toFloat() * rhs.toFloat())); }
const Fixed	Fixed::operator/(const Fixed& rhs) const	{ return (Fixed(toFloat() / rhs.toFloat())); }
const Fixed	Fixed::operator-() const					{ return (Fixed(toFloat() * -1.0f)); }

Fixed&	Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	old(*this);
	operator++();
	return (old);
}

Fixed&	Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	old(*this);
	operator--();
	return (old);
}

Fixed&			Fixed::min(Fixed& lhs, Fixed& rhs)				{ return (lhs < rhs ? lhs : rhs); }
const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs)	{ return (lhs < rhs ? lhs : rhs); }
Fixed&			Fixed::max(Fixed& lhs, Fixed& rhs)				{ return (lhs > rhs ? lhs : rhs); }
const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs)	{ return (lhs > rhs ? lhs : rhs); }
