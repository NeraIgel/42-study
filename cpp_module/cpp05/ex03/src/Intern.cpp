/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:56:53 by heha              #+#    #+#             */
/*   Updated: 2023/01/09 12:12:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Intern::Intern()
{}

Intern::Intern(const Intern& rhs)
{
	(void)rhs;
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

AForm	*Intern::makeForm(const std::string& formName, const std::string& target) const
{
	return (makeForm(formName.c_str(), target.c_str()));
}

AForm	*Intern::makeForm(const char *pFormName, const char *pTarget) const
{
	static const MapStringToFunction	mapCreateFormFunction[] = {
		{ "ShrubberyCreationForm",	&Intern::_createShrubberyCreationForm },
		{ "RobotomyRequestForm",	&Intern::_createRobotomyRequestForm },
		{ "PresidentialPardonForm",	&Intern::_createPresidentialPardonForm },
		{ NULL,						&Intern::_createFormException },
	};

	const MapStringToFunction	*p = mapCreateFormFunction;
	while (p->formName && std::strcmp(p->formName, pFormName))
		++p;
	return ((this->*p->func)(pTarget));
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Intern&	Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{}

const char	*Intern::UnknownFormNameException::what() const throw()
{
	return ("\033[31;1mException:\033[0m An unknown form name was requested");
}

AForm	*Intern::_createShrubberyCreationForm(const char *pTarget) const
{
	std::cout << "Intern creates " << "ShrubberyCreationForm " << pTarget << std::endl;
	return (new ShrubberyCreationForm(pTarget));
}

AForm	*Intern::_createRobotomyRequestForm(const char *pTarget) const
{
	std::cout << "Intern creates " << "RobotomyRequestForm " << pTarget << std::endl;
	return (new RobotomyRequestForm(pTarget));
}

AForm	*Intern::_createPresidentialPardonForm(const char *pTarget) const
{
	std::cout << "Intern creates " << "PresidentialPardonForm " << pTarget << std::endl;
	return (new PresidentialPardonForm(pTarget));
}

AForm	*Intern::_createFormException(const char *pTarget) const
{
	throw UnknownFormNameException();
	(void)pTarget;
	return (NULL);
}
