/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:53:52 by heha              #+#    #+#             */
/*   Updated: 2022/12/29 19:49:20 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <fstream>
#include <iostream>
#include "Replace.hpp"

// ************************************************************************** //
//                                Internals                                   //
// ************************************************************************** //

static bool	_error(const char *lpszText)
{
	std::ostringstream	oss;
	oss << "\033[31;1m" << "[ ERROR ] " << "\033[0m" << lpszText;
	std::cout << oss.str() << std::endl;
	return (false);
}

static std::size_t	_replace(std::string& dst, const std::string& s1, const std::string& s2)
{
	std::size_t	s1_len = s1.length();
	std::size_t	s2_len = s2.length();
	std::size_t	count = 0;

	for (std::size_t pos = 0; std::string::npos != (pos = dst.find(s1, pos)); pos += s2_len, ++count)
	{
		dst.erase(pos, s1_len);
		dst.insert(pos, s2);
	}
	return (count);
}

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Replace::Replace(const std::string& filename)
	: _filename(filename)
{}

Replace::Replace(const Replace& rhs)
	: _filename(rhs._filename)
{}

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

bool	Replace::execute(const std::string& s1, const std::string& s2) const
{
	if (_filename.empty() || s1.empty() || s2.empty())
		return (_error("argument string is empty."));

	std::ifstream	inFile(_filename.c_str(), inFile.binary | inFile.in);
	if (!inFile.is_open())
		return (_error("inFile could not be opened."));

	std::string		replaceFilename(_filename + ".replace");
	std::ofstream	outFile(replaceFilename.c_str(), outFile.binary | outFile.trunc | outFile.out);
	if (!outFile.is_open())
		return (_error("outFile could not be opend."));

	std::ostringstream	oss;
	oss << inFile.rdbuf();

	std::string	temp = oss.str();
	_replace(temp, s1, s2);
	outFile << temp;

	outFile.close();
	inFile.close();

	return (true);
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Replace&	Replace::operator=(const Replace& rhs)
{
	_filename = rhs._filename;
	return (*this);
}

Replace::~Replace()
{}
