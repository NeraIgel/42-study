/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:57:47 by heha              #+#    #+#             */
/*   Updated: 2023/01/03 21:17:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

// ************************************************************************** //
//                         RobotomyRequestForm Class                          //
// ************************************************************************** //

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:
	explicit RobotomyRequestForm(const std::string& target);
	explicit RobotomyRequestForm(const char *pTarget = "Anonymous");
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	~RobotomyRequestForm();

	virtual void	execute(const Bureaucrat& executor) const;

private:
	static const int	_DefaultGradeToSign = 72;
	static const int	_DefaultGradeToExecute = 45;

};

#endif
