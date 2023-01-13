/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:41:18 by heha              #+#    #+#             */
/*   Updated: 2023/01/12 21:12:13 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

// ************************************************************************** //
//                                 Span Class                                 //
// ************************************************************************** //

# include <set>
# include <vector>

class Span {

public:
	explicit Span(unsigned int N);
	Span(const Span& rhs);
	Span& operator=(const Span& rhs);
	~Span();

	std::vector<int>::const_iterator	getBegin() const;

	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	void	addNumber(int number);
	void	addNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);
	void	showNumber() const;

private:
	Span();

	std::set<int>		_set;
	std::vector<int>	_vector;

};

#endif
