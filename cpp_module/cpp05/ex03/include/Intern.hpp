/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:51:48 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 19:39:03 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

// ************************************************************************** //
//                                 Intern Class                               //
// ************************************************************************** //

# include <string>
# include <exception>
# include "AForm.hpp"

class Intern {

public:
	explicit Intern();
	Intern(const Intern& rhs);
	Intern& operator=(const Intern& rhs);
	~Intern();

	AForm	*makeForm(const std::string& formName, const std::string& target) const;
	AForm	*makeForm(const char *pFormName, const char *pTarget) const;

private:
	class UnknownFormNameException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};

	typedef AForm	*(Intern::*func_pointer_t)(const char *) const;

	struct MapStringToFunction {
		const char		*formName;
		func_pointer_t	func;
	};

	AForm	*_createShrubberyCreationForm(const char *pTarget) const;
	AForm	*_createRobotomyRequestForm(const char *pTarget) const;
	AForm	*_createPresidentialPardonForm(const char *pTarget) const;
	AForm	*_createFormException(const char *pTarget) const;

};

#endif
