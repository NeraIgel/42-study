/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:55:58 by heha              #+#    #+#             */
/*   Updated: 2023/01/13 16:33:45 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include "Span.hpp"

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

Span::Span(unsigned int N)
	: _set(), _vector()
{
	_vector.reserve(N);
}

Span::Span(const Span& rhs)
	: _set(rhs._set), _vector(rhs._vector)
{
	_vector.reserve(rhs._vector.capacity());
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

std::vector<int>::const_iterator	Span::getBegin() const	{ return(_vector.begin()); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

unsigned int	Span::shortestSpan() const
{
	if (_vector.size() <= 1)
	{
		std::ostringstream	oss;
		oss << "Shortest Span could not be obtained due to insufficient stored count." << " (size: " << _vector.size() << ')';
		throw std::runtime_error(oss.str());
	}

	if (_set.size() != _vector.size())
	{
		return (0);
	}
	else
	{
		unsigned int			halfPosition = _set.size() / 2 - 1;
		std::set<int>::iterator	iter = _set.begin();
		for (unsigned int i = 0; i < halfPosition; ++i)
			++iter;

		int	a = *iter;
		int	b = *(++iter);
		if (_set.size() % 2 == 0)
		{
			return (b - a);
		}
		else
		{
			int	c = *(++iter);
			return ((b - a < c - b) ? b - a : c - b);
		}
	}
}

unsigned int	Span::longestSpan() const
{
	if (_vector.size() <= 1)
	{
		std::ostringstream	oss;
		oss << "Longest Span could not be obtained due to insufficient stored count." << " (size: " << _vector.size() << ')';
		throw std::runtime_error(oss.str());
	}

	std::set<int>::iterator			iter1 = _set.begin();
	std::set<int>::reverse_iterator	iter2 = _set.rbegin();
	return (*iter2 - *iter1);
}

void	Span::addNumber(int number)
{
	if (_vector.size() == _vector.capacity())
	{
		std::ostringstream	oss;
		oss << "The capacity range has been exceeded." << " (size: " << _vector.size() << ", capacity: " << _vector.capacity() << ')';
		throw std::runtime_error(oss.str());
	}
	_vector.push_back(number);
	_set.insert(number);
}

void	Span::addNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
	if (static_cast<std::size_t>(std::distance(first, last)) > _vector.capacity() - _vector.size())
	{
		std::ostringstream	oss;
		oss << "The capacity range has been exceeded." << " (request: " << std::distance(first, last) << ", available: " << _vector.capacity() - _vector.size() << ')';
		throw std::runtime_error(oss.str());
	}

	std::srand(std::time(NULL));
	while (first != last)
	{
		addNumber(std::rand());
		++first;
	}
}

void	Span::showNumber() const
{
	std::ostringstream	oss;
	for (std::vector<int>::const_iterator iter = _vector.begin(); iter != _vector.end(); ++iter)
	{
		oss << *iter << ' ';
	}
	std::cout << oss.str() << std::endl;
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

Span::Span()
{}

Span::~Span()
{}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_set = rhs._set;
		_vector = rhs._vector;
		_vector.reserve(rhs._vector.capacity());
	}
	return (*this);
}
