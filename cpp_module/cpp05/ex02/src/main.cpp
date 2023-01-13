/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:56:12 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 17:38:45 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	doAFormTest(void)
{
	try
	{
		AForm	*s = new ShrubberyCreationForm("s");
		AForm	*r = new RobotomyRequestForm("r");
		AForm	*p = new PresidentialPardonForm("p");

		std::cout << *s << std::endl;
		std::cout << *r << std::endl;
		std::cout << *p << std::endl;
		*s = *r;
		std::cout << *s << std::endl;

		ShrubberyCreationForm	*ptr = dynamic_cast<ShrubberyCreationForm *>(s);
		if (!ptr)
			throw std::exception();
		ShrubberyCreationForm	ss(*ptr);
		std::cout << ss << std::endl;

		delete s;
		delete r;
		delete p;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	doAFormTest(const char *pFormName, int bureaucratGrade)
{
	std::cout << std::endl;
	try
	{
		Bureaucrat	bureaucrat("bureaucrat", bureaucratGrade);
		AForm		*pf;

		pf = new ShrubberyCreationForm(pFormName);
		std::cout << *pf << " / " << bureaucrat << std::endl;
		bureaucrat.signForm(*pf);
		bureaucrat.executeForm(*pf);
		delete pf;

		pf = new RobotomyRequestForm(pFormName);
		std::cout << *pf << " / " << bureaucrat << std::endl;
		bureaucrat.signForm(*pf);
		bureaucrat.executeForm(*pf);
		delete pf;

		pf = new PresidentialPardonForm(pFormName);
		std::cout << *pf << " / " << bureaucrat << std::endl;
		bureaucrat.signForm(*pf);
		bureaucrat.executeForm(*pf);
		delete pf;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	leakCheck(void)
{
	std::cout << std::endl;
	std::system("leaks --list -- a.out");
}

int	main(void)
{
	doAFormTest();
	doAFormTest("A", 5);
	doAFormTest("B", 45);
	doAFormTest("C", 137);
	doAFormTest("D", 150);
	leakCheck();
	return (EXIT_SUCCESS);
}
