/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:04:55 by heha              #+#    #+#             */
/*   Updated: 2023/01/09 12:09:12 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Converter.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Converter::Converter(const std::string& input)
	: _input(input)
{
	_replaceInputString();
	_convertToNumber();
}

Converter::Converter(const char *pInput)
	: _input(pInput)
{
	_replaceInputString();
	_convertToNumber();
}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

void	Converter::toChar() const
{
	std::ostringstream	oss;

	oss << "char: ";
	if (_isPossibleConversion && _number >= std::numeric_limits<char>::min() && _number <= std::numeric_limits<char>::max())
	{
		if (std::isprint(static_cast<int>(_number)))	oss << '\'' << static_cast<char>(_number) << '\'';
		else 											oss << "Non displayable";
	}
	else
		oss << "impossible";
	std::cout << oss.str() << std::endl;
}

void	Converter::toInt() const
{
	std::ostringstream	oss;

	oss << "int: ";
	if (_isPossibleConversion && _number >= std::numeric_limits<int>::min() && _number <= std::numeric_limits<int>::max())
	{
		oss << static_cast<int>(_number);
	}
	else
		oss << "impossible";
	std::cout << oss.str() << std::endl;
}

void	Converter::toFloat() const
{
	std::ostringstream	oss;

	oss << "float: ";
	if (_isPossibleConversion)
	{
		if (std::abs(_number - static_cast<int>(_number)) < 1e-12)	oss << std::setprecision(1);
		else														oss << std::setprecision(std::numeric_limits<float>::digits10);
		oss << std::fixed << static_cast<float>(_number) << 'f';
	}
	else
		oss << "impossible";
	std::cout << oss.str() << std::endl;
}

void	Converter::toDouble() const
{
	std::ostringstream	oss;

	oss << "double: ";
	if (_isPossibleConversion)
	{
		if (std::abs(_number - static_cast<int>(_number)) < 1e-12)	oss << std::setprecision(1);
		else														oss << std::setprecision(std::numeric_limits<double>::digits10);
		oss << std::fixed << _number;
	}
	else
		oss << "impossible";
	std::cout << oss.str() << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Converter::Converter()
{}

Converter::Converter(const Converter& rhs)
{
	(void)rhs;
}

Converter&	Converter::operator=(const Converter& rhs)
{
	(void)rhs;
	return (*this);
}

Converter::~Converter()
{}

void	Converter::_replaceInputString()
{
	std::size_t	length = _input.length();

	for (std::size_t i = 0; i < length; ++i)
	{
		_input[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(_input[i])));
	}

	if (_input == "inff" || _input == "+inff" || _input == "-inff" || _input == "nanf" || _input == "+nanf" || _input == "-nanf")
		_input.erase(_input.end() - 1);
	else if (length >= 2 && _input[length - 1] == 'f' && !std::isalpha(_input[length - 2]))
		_input.erase(_input.end() - 1);
}

void	Converter::_convertToNumber()
{
	std::istringstream	stream(_input);

	stream >> _number;
	if (_input == "nan" || _input == "+nan" || _input == "-nan")
	{
		_number = std::numeric_limits<double>::quiet_NaN();
		_isPossibleConversion = true;
	}
	else if (_input == "inf" || _input == "+inf")
	{
		_number = std::numeric_limits<double>::infinity();
		_isPossibleConversion = true;
	}
	else if (_input == "-inf")
	{
		_number = -std::numeric_limits<double>::infinity();
		_isPossibleConversion = true;
	}
	else if (stream && stream.get() && stream.eof())
		_isPossibleConversion = true;
	else
		_isPossibleConversion = false;
}
