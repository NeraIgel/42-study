/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:09:46 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 16:34:20 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, PresidentialPardonForm::_DefaultGradeToSign, PresidentialPardonForm::_DefaultGradeToExecute)
{}

PresidentialPardonForm::PresidentialPardonForm(const char *pTarget)
	: AForm(pTarget, PresidentialPardonForm::_DefaultGradeToSign, PresidentialPardonForm::_DefaultGradeToExecute)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
	: AForm(rhs)
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::_checkExecuteCondition(getSigned(), getGradeToExecute(), executor.getGrade());

	std::cout << " >> " << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}
