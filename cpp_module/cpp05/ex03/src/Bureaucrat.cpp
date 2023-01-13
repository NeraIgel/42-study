/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:18:50 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 13:22:55 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Bureaucrat.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
{
	Bureaucrat::_isValidGrade(grade);
	_grade = grade;
}

Bureaucrat::Bureaucrat(const char *pName, int grade)
	: _name(pName)
{
	Bureaucrat::_isValidGrade(grade);
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
	: _name(rhs.getName()), _grade(rhs.getGrade())
{}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

const std::string&	Bureaucrat::getName() const		{ return(_name); }
int					Bureaucrat::getGrade() const	{ return(_grade); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Bureaucrat::incrementGrade()
{
	Bureaucrat::_isValidGrade(getGrade() - 1);
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	Bureaucrat::_isValidGrade(getGrade() + 1);
	++_grade;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string&>(_name) = rhs.getName();
		_grade = rhs.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

void	Bureaucrat::exception(const std::exception& e) const
{
	std::ostringstream	oss;
	oss << "\033[31;1mException:\033[0m " << getName() << ", " << e.what();
	std::cerr << oss.str() << std::endl;
}

const char	*Bureaucrat::GradeNegativeException::what() const throw()
{
	return ("bureaucrat grade is negative value");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("bureaucrat grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("bureaucrat grade is too low");
}

void	Bureaucrat::_isValidGrade(int grade)
{
	if		(grade < 0)								throw GradeNegativeException();
	else if (grade < Bureaucrat::_GradeHighLimit)	throw GradeTooHighException();
	else if (grade > Bureaucrat::_GradeLowLimit)	throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	std::ostringstream	oss;
	oss << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	os << oss.str();
	return (os);
}
