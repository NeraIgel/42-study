/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:01:57 by heha              #+#    #+#             */
/*   Updated: 2023/01/03 21:17:30 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

// ************************************************************************** //
//                        PresidentialPardonForm Class                        //
// ************************************************************************** //

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:
	explicit PresidentialPardonForm(const std::string& target);
	explicit PresidentialPardonForm(const char *pTarget = "Anonymous");
	PresidentialPardonForm(const PresidentialPardonForm& rhs);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
	~PresidentialPardonForm();

	virtual void	execute(const Bureaucrat& executor) const;

private:
	static const int	_DefaultGradeToSign = 25;
	static const int	_DefaultGradeToExecute = 5;

};

#endif
