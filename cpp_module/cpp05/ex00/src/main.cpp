/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:32:50 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 13:21:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

static void	doBureaucratTest(void)
{
	try
	{
		Bureaucrat	bureaucrat1("bureaucrat1", 1);
		Bureaucrat	bureaucrat2(bureaucrat1);
		Bureaucrat	bureaucrat3;

		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;

		bureaucrat3 = bureaucrat1;
		std::cout << bureaucrat3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	doBureaucratTest(const char *pName, int grade)
{
	Bureaucrat	bureaucrat(pName);
	try
	{
		bureaucrat = Bureaucrat(pName, grade);

		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		bureaucrat.exception(e);
	}
}

int	main(void)
{
	doBureaucratTest();
	doBureaucratTest("A", -1);
	doBureaucratTest("B", 0);
	doBureaucratTest("C", 1);
	doBureaucratTest("D", 42);
	doBureaucratTest("E", 150);
	doBureaucratTest("F", 151);
	return (EXIT_SUCCESS);
}
