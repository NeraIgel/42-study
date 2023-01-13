/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:35:27 by heha              #+#    #+#             */
/*   Updated: 2022/12/13 16:56:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

/*	std::cout << std::endl;

	std::cout << std::boolalpha << (a > b) << std::endl;
	std::cout << std::boolalpha << (a < b) << std::endl;
	std::cout << std::boolalpha << (a >= b) << std::endl;
	std::cout << std::boolalpha << (a <= b) << std::endl;
	std::cout << std::boolalpha << (a == b) << std::endl;
	std::cout << std::boolalpha << (a != b) << std::endl;
	std::cout << std::endl;

	std::cout << std::boolalpha << (a > a) << std::endl;
	std::cout << std::boolalpha << (a < a) << std::endl;
	std::cout << std::boolalpha << (a >= a) << std::endl;
	std::cout << std::boolalpha << (a <= a) << std::endl;
	std::cout << std::boolalpha << (a == a) << std::endl;
	std::cout << std::boolalpha << (a != a) << std::endl;
	std::cout << std::endl;

	std::cout << std::boolalpha << (b > b) << std::endl;
	std::cout << std::boolalpha << (b < b) << std::endl;
	std::cout << std::boolalpha << (b >= b) << std::endl;
	std::cout << std::boolalpha << (b <= b) << std::endl;
	std::cout << std::boolalpha << (b == b) << std::endl;
	std::cout << std::boolalpha << (b != b) << std::endl;
	std::cout << std::endl;

	std::cout << a + Fixed(1) << std::endl;
	std::cout << a + Fixed(-1) << std::endl;
	std::cout << a + Fixed(42) << std::endl;
	std::cout << std::endl;

	std::cout << a - Fixed(1) << std::endl;
	std::cout << a - Fixed(-1) << std::endl;
	std::cout << a - Fixed(42) << std::endl;
	std::cout << std::endl;

	std::cout << a * Fixed(1) << std::endl;
	std::cout << a * Fixed(-1) << std::endl;
	std::cout << a * Fixed(2) << std::endl;
	std::cout << std::endl;

	std::cout << a / Fixed(1) << std::endl;
	std::cout << a / Fixed(-1) << std::endl;
	std::cout << a / Fixed(2) << std::endl;
	std::cout << std::endl;

	std::cout << -a << std::endl;
	std::cout << std::endl;

	Fixed	c(a);
	std::cout << c << std::endl;
	std::cout << --c << std::endl;
	std::cout << c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;

	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::min(a, a) << std::endl;
	std::cout << Fixed::min(b, b) << std::endl;
	std::cout << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::max(a, a) << std::endl;
	std::cout << Fixed::max(b, b) << std::endl;*/

	return 0;
}
