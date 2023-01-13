/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:08:30 by heha              #+#    #+#             */
/*   Updated: 2023/01/04 16:44:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, ShrubberyCreationForm::_DefaultGradeToSign, ShrubberyCreationForm::_DefaultGradeToExecute)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const char *pTarget)
	: AForm(pTarget, ShrubberyCreationForm::_DefaultGradeToSign, ShrubberyCreationForm::_DefaultGradeToExecute)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	: AForm(rhs)
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::_checkExecuteCondition(getSigned(), getGradeToExecute(), executor.getGrade());

	std::string		outFileName = getName();
	outFileName += "_shrubbery";
	std::ofstream	outFile(outFileName.c_str(), outFile.binary | outFile.trunc | outFile.out);
	if (!outFile.is_open())
		throw FileOpenFailedException();

	std::string	treeString = 
		"          &&& &&  & &&\n"
		"      && &\\/&\\|& ()|/ @, &&\n"
		"      &\\/(/&/&||/& /_/)_&/_&\n"
		"   &() &\\/&|()|/&\\/ '%\" & ()\n"
		"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
		"&&   && & &| &| /& & % ()& /&&\n"
		" ()&_---()&\\&\\|&&-&&--%---()~\n"
		"     &&     \\|||\n"
		"             |||\n"
		"             |||\n"
		"             |||\n"
		"       , -=-~  .-^- _\n"
		"ejm97         `\"\n";

	outFile << treeString;
	outFile.close();
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const char	*ShrubberyCreationForm::FileOpenFailedException::what() const throw()
{
	return ("file open is failed");
}
