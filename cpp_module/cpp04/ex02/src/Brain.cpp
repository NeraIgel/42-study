/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:58:30 by heha              #+#    #+#             */
/*   Updated: 2023/01/02 16:45:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Brain.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Brain::Brain()
{
	Brain::_logBrain("constructor called");
}

Brain::Brain(const Brain& rhs)
{
	Brain::_logBrain("copy constructor called");
	*this = rhs;
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

std::string&	Brain::operator[](std::size_t position)
{
	return (
			const_cast<std::string&>(
				static_cast<const Brain&>(
					*this)[position]
				)
		   );
}

const std::string&	Brain::operator[](std::size_t position) const
{
	if (position >= _NumOfIdeas)
		_error("invalid index access error.");
	return (_ideasArray[position]);
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Brain&	Brain::operator=(const Brain& rhs)
{
	Brain::_logBrain("copy assignment operator called");
	if (this != &rhs)
	{
		for (std::size_t i = 0; i < _NumOfIdeas; ++i)
			_ideasArray[i] = rhs._ideasArray[i];
	}
	return (*this);
}

Brain::~Brain()
{
	Brain::_logBrain("destructor called");
}

void	Brain::_logBrain(const std::string& logInfo)
{
	Brain::_logBrain(logInfo.c_str());
}

void	Brain::_logBrain(const char *pLogInfo)
{
	std::ostringstream	oss;
	oss << "Brain " << pLogInfo;
	std::cout << oss.str() << std::endl;
}

void	Brain::_error(const std::string& errorMsg)
{
	Brain::_error(errorMsg.c_str());
}

void	Brain::_error(const char *pErrorMsg)
{
	std::ostringstream	oss;
	oss << "\033[31;1mError:\033[0m " << pErrorMsg;
	std::cerr << oss.str() << std::endl;
	std::exit(EXIT_FAILURE);
}
