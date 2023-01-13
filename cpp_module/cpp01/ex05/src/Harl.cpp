/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:56:04 by heha              #+#    #+#             */
/*   Updated: 2022/11/17 17:22:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Harl::Harl()
{}

Harl::Harl(const Harl& rhs)
{
	(void)rhs;
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Harl::complain(std::string level) const
{
	static const MapStringToFunction mapLoggingFunction[] = {
		{ "DEBUG",	&Harl::_debug },
		{ "INFO",	&Harl::_info },
		{ "WARNING",&Harl::_warning },
		{ "ERROR",	&Harl::_error },
		{ NULL,		&Harl::_exception }
	};

	const MapStringToFunction	*p = mapLoggingFunction;
	while (p->level && p->level != level)
		++p;
	(this->*p->func)();
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Harl::~Harl()
{}

Harl&	Harl::operator=(const Harl& rhs)
{
	(void)rhs;
	return (*this);
}

void	Harl::_debug(void) const
{
	std::cout \
		<< "\033[0;1m" << "[ DEBUG ]" << "\033[0m\n" \
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" \
		<< std::endl;
}

void	Harl::_info(void) const
{
	std::cout \
		<< "\033[32;1m" << "[ INFO ]" << "\033[0m\n" \
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" \
		<< std::endl;
}

void	Harl::_warning(void) const
{
	std::cout \
		<< "\033[33;1m" << "[ WARNING ]" << "\033[0m\n" \
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" \
		<< std::endl;
}

void	Harl::_error(void) const
{
	std::cout \
		<< "\033[31;1m" << "[ ERROR ]" << "\033[0m\n" \
		<< "This is unacceptable! I want to speak to the manager now.\n" \
		<< std::endl;
}

void	Harl::_exception(void) const
{
	std::cout \
		<< "\033[30;1m" << "[ Probably complaining about insignificant problems ]" << "\033[0m" \
		<< std::endl;
}
