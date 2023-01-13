/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:53:02 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 13:32:49 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

// ************************************************************************** //
//                        ShrubberyCreationForm Class                         //
// ************************************************************************** //

# include <string>
# include <exception>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:
	explicit ShrubberyCreationForm(const std::string& target);
	explicit ShrubberyCreationForm(const char *pTarget = "Anonymous");
	ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm();

	virtual void	execute(const Bureaucrat& executor) const;

private:
	class FileOpenFailedException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};

	static const int	_DefaultGradeToSign = 145;
	static const int	_DefaultGradeToExecute = 137;

};

#endif
