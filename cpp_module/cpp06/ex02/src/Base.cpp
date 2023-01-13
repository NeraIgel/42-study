/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:05:48 by heha              #+#    #+#             */
/*   Updated: 2023/01/09 12:11:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Base::~Base()
{}

Base	*generate()
{
	std::srand(std::time(NULL));
    int	random_variable = std::rand();

	Base	*pb;
	if 		(random_variable % 3 == 0)	pb = new A;
	else if (random_variable % 3 == 1)	pb = new B;
	else								pb = new C;
	return (pb);
}

void	identify(Base *p)
{
	if 		(dynamic_cast<A *>(p))	std::cout << "This pointer points to an A object." << std::endl;
	else if (dynamic_cast<B *>(p))	std::cout << "This pointer points to an B object." << std::endl;
	else if (dynamic_cast<C *>(p))	std::cout << "This pointer points to an C object." << std::endl;
	else							std::cerr << "\033[31;1mException:\033[0m " << "This pointer could not be identified." << std::endl;
}

void	identify(Base& r)
{
	try
	{
		A&	ra = dynamic_cast<A&>(r);	(void)ra;
		std::cout << "This reference is an alias for the A object." << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			B&	rb = dynamic_cast<B&>(r);	(void)rb;
			std::cout << "This reference is an alias for the B object." << std::endl;
		}
		catch (const std::exception& e)
		{
			try
			{
				C&	rc = dynamic_cast<C&>(r);	(void)rc;
				std::cout << "This reference is an alias for the C object." << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cerr << "\033[31;1mException:\033[0m " << "This reference could not be identified." << std::endl;
			}
		}
	}
}
