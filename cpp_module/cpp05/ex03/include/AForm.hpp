/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:02:03 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 12:19:30 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

// ************************************************************************** //
//                                 AForm Class                                //
// ************************************************************************** //

# include <string>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

public:
	explicit AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	explicit AForm(const char *pName = "Anonymous", int gradeToSign = AForm::_GradeLowLimit, int gradeToExecute = AForm::_GradeLowLimit);
	AForm(const AForm& rhs);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& executor) const = 0;

	void			exception(const std::exception& e) const;

protected:
	static void		_checkExecuteCondition(bool sign, int formGrade, int bureaucratGrade);

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
	class NotSignedException : public std::exception {
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

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif
