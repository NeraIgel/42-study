/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:09:39 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 12:20:51 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "AForm.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	AForm::_isValidGrade(gradeToSign);
	AForm::_isValidGrade(gradeToExecute);
}

AForm::AForm(const char *pName, int gradeToSign, int gradeToExecute)
	: _name(pName), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	AForm::_isValidGrade(gradeToSign);
	AForm::_isValidGrade(gradeToExecute);
}

AForm::AForm(const AForm& rhs)
	: _name(rhs.getName()), _signed(rhs.getSigned()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute())
{}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

const std::string&	AForm::getName() const				{ return(_name); }
bool				AForm::getSigned() const			{ return(_signed); }
int					AForm::getGradeToSign() const		{ return(_gradeToSign); }
int					AForm::getGradeToExecute() const	{ return(_gradeToExecute); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_signed = true;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

AForm&	AForm::operator=(const AForm& rhs)
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

AForm::~AForm()
{}

void	AForm::exception(const std::exception& e) const
{
	std::ostringstream	oss;
	oss << "\033[31;1mException:\033[0m " << getName() << ", " << e.what();
	std::cerr << oss.str() << std::endl;
}

const char	*AForm::GradeNegativeException::what() const throw()
{
	return ("form grade is negative value");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("form grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("form grade is too low");
}

const char	*AForm::NotSignedException::what() const throw()
{
	return ("form is not signed");
}

void	AForm::_checkExecuteCondition(bool sign, int formGrade, int bureaucratGrade)
{
	if 		(!sign)							throw NotSignedException();
	else if (bureaucratGrade > formGrade)	throw GradeTooLowException();
}

void	AForm::_isValidGrade(int grade)
{
	if		(grade < 0)							throw GradeNegativeException();
	else if (grade < AForm::_GradeHighLimit)	throw GradeTooHighException();
	else if (grade > AForm::_GradeLowLimit)		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	std::ostringstream	oss;
	oss << std::boolalpha;
	oss << obj.getName() << ", form signed " << obj.getSigned() << ", gradeToSign " << obj.getGradeToSign() << ", gradeToExecute " << obj.getGradeToExecute();
	os << oss.str();
	return (os);
}
