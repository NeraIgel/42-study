/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:25:45 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 13:22:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

static void	doFormTest(void)
{
	try
	{
		Form	form1("form1", 1, 2);
		Form	form2(form1);
		Form	form3;

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;

		form3 = form1;
		std::cout << form3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	doFormTest(const char *pName, int formGrade, int bureaucratGrade)
{
	std::cout << std::endl;
	Form	form(pName);
	try
	{
		form = Form(pName, formGrade, formGrade);
		Bureaucrat	bureaucrat("bureaucrat", bureaucratGrade);

		std::cout << form << " / " << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception& e)
	{
		form.exception(e);
	}
}

int	main(void)
{
	doFormTest();
	doFormTest("A", -1, -1);
	doFormTest("B", 0, 0);
	doFormTest("C", 1, 1);
	doFormTest("D", 42, 41);
	doFormTest("E", 42, 42);
	doFormTest("F", 42, 43);
	doFormTest("G", 150, 150);
	doFormTest("H", 151, 151);
	return (EXIT_SUCCESS);
}
