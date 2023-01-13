/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:49:34 by heha              #+#    #+#             */
/*   Updated: 2022/12/13 12:20:18 by heha             ###   ########.fr       */
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

private:
	static const int	_FractionalBits = 8;
	int					_value;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
