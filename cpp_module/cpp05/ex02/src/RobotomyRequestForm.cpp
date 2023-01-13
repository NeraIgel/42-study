/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:09:24 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 16:36:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RobotomyRequestForm.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, RobotomyRequestForm::_DefaultGradeToSign, RobotomyRequestForm::_DefaultGradeToExecute)
{}

RobotomyRequestForm::RobotomyRequestForm(const char *pTarget)
	: AForm(pTarget, RobotomyRequestForm::_DefaultGradeToSign, RobotomyRequestForm::_DefaultGradeToExecute)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
	: AForm(rhs)
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::_checkExecuteCondition(getSigned(), getGradeToExecute(), executor.getGrade());

	std::cout << " >> " << getName() << " drilling noises." << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << " >> " << getName() << " is successfully robotized." << std::endl;
	else
		std::cout << " >> " << getName() << " failed to robotize." << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
