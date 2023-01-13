/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:21:41 by heha              #+#    #+#             */
/*   Updated: 2023/01/03 16:45:29 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

// ************************************************************************** //
//                                 Form Class                                 //
// ************************************************************************** //

# include <string>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:
	explicit Form(const std::string& name, int gradeToSign, int gradeToExecute);
	explicit Form(const char *pName = "Anonymous", int gradeToSign = Form::_GradeLowLimit, int gradeToExecute = Form::_GradeLowLimit);
	Form(const Form& rhs);
	Form& operator=(const Form& rhs);
	~Form();

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void	beSigned(const Bureaucrat& bureaucrat);

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
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
