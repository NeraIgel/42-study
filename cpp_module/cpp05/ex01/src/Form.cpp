/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:42:12 by heha              #+#    #+#             */
/*   Updated: 2023/01/03 20:46:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Form.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	Form::_isValidGrade(gradeToSign);
	Form::_isValidGrade(gradeToExecute);
}

Form::Form(const char *pName, int gradeToSign, int gradeToExecute)
	: _name(pName), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	Form::_isValidGrade(gradeToSign);
	Form::_isValidGrade(gradeToExecute);
}

Form::Form(const Form& rhs)
	: _name(rhs.getName()), _signed(rhs.getSigned()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute())
{}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

const std::string&	Form::getName() const			{ return(_name); }
bool				Form::getSigned() const			{ return(_signed); }
int					Form::getGradeToSign() const	{ return(_gradeToSign); }
int					Form::getGradeToExecute() const	{ return(_gradeToExecute); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_signed = true;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Form&	Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string&>(_name) = rhs.getName();
		_signed = rhs.getSigned();
		const_cast<int&>(_gradeToSign) = rhs.getGradeToSign();
		const_cast<int&>(_gradeToExecute) = rhs.getGradeToExecute();
	}
	return (*this);
}

Form::~Form()
{}

void	Form::exception(const std::exception& e) const
{
	std::ostringstream	oss;
	oss << "\033[31;1mException:\033[0m " << getName() << ", " << e.what();
	std::cerr << oss.str() << std::endl;
}

const char	*Form::GradeNegativeException::what() const throw()
{
	return ("form grade is negative value");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("form grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("form grade is too low");
}

void	Form::_isValidGrade(int grade)
{
	if		(grade < 0)						throw GradeNegativeException();
	else if (grade < Form::_GradeHighLimit)	throw GradeTooHighException();
	else if (grade > Form::_GradeLowLimit)	throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	std::ostringstream	oss;
	oss << std::boolalpha;
	oss << obj.getName() << ", form signed " << obj.getSigned() << ", gradeToSign " << obj.getGradeToSign() << ", gradeToExecute " << obj.getGradeToExecute();
	os << oss.str();
	return (os);
}
