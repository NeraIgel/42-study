/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:18:33 by heha              #+#    #+#             */
/*   Updated: 2023/01/03 20:34:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// ************************************************************************** //
//                              Bureaucrat Class                              //
// ************************************************************************** //

# include <string>
# include <ostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {

public:
	explicit Bureaucrat(const std::string& name, int grade);
	explicit Bureaucrat(const char *pName = "Anonymous", int grade = Bureaucrat::_GradeLowLimit);
	Bureaucrat(const Bureaucrat& rhs);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	const std::string&	getName() const;
	int					getGrade() const;

	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm& form) const;
	void	executeForm(const AForm& form) const;

	void	exception(const std::exception& e) const;

private:
	class GradeNegativeException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};
	static void			_isValidGrade(int grade);
	static const int	_GradeHighLimit = 1;
	static const int	_GradeLowLimit = 150;

	const std::string	_name;
	int					_grade;

};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
