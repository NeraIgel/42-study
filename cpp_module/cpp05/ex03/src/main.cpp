/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:56:12 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 19:45:11 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

static void	doInternTest(void)
{
	try
	{
		Intern	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	doInternTest(const char *pTarget, const char *pFormName)
{
	std::cout << std::endl;
	try
	{
		Bureaucrat	bureaucrat("bureaucrat", 1);
		Intern		intern;
		AForm		*pForm;

		pForm = intern.makeForm(pFormName, pTarget);
		if (pForm)
		{
			std::cout << *pForm << " / " << bureaucrat << std::endl;
			bureaucrat.signForm(*pForm);
			bureaucrat.executeForm(*pForm);
			delete pForm;
		}
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
	doInternTest();
	doInternTest("A", "ShrubberyCreationForm");
	doInternTest("B", "RobotomyRequestForm");
	doInternTest("C", "PresidentialPardonForm");
	leakCheck();
	return (EXIT_SUCCESS);
}
