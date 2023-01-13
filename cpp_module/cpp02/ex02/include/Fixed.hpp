/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:49:34 by heha              #+#    #+#             */
/*   Updated: 2022/12/13 15:33:05 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

// ************************************************************************** //
//                                Fixed Class                                 //
// ************************************************************************** //

# include <ostream>

class Fixed {

public:
	explicit Fixed();
	explicit Fixed(const int n);
	explicit Fixed(const float n);
	Fixed(const Fixed& rhs);
	Fixed& operator=(const Fixed& rhs);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;

	const Fixed	operator+(const Fixed& rhs) const;
	const Fixed	operator-(const Fixed& rhs) const;
	const Fixed	operator*(const Fixed& rhs) const;
	const Fixed	operator/(const Fixed& rhs) const;
	const Fixed	operator-() const;

	Fixed&		operator++();
	const Fixed	operator++(int);
	Fixed&		operator--();
	const Fixed	operator--(int);

	static Fixed&		min(Fixed& lhs, Fixed& rhs);
	static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
	static Fixed&		max(Fixed& lhs, Fixed& rhs);
	static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);

private:
	static const int	_FractionalBits = 8;
	int					_value;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
