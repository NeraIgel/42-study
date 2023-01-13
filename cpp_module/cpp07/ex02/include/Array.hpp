/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:58:47 by heha              #+#    #+#             */
/*   Updated: 2023/01/10 16:34:21 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

// ************************************************************************** //
//                                 Array Class                                //
// ************************************************************************** //

# include <exception>

template <typename T>
class Array {

public:
	explicit Array();
	explicit Array(unsigned int n);
	Array(const Array& rhs);
	Array& operator=(const Array& rhs);
	~Array();

	unsigned int	size() const;

	T&			operator[](unsigned int position);
	const T&	operator[](unsigned int position) const;

private:
	class OutOfRangeException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};

	void	_initArray();
	void	_clearArray();
	void	_copyArray(const Array& rhs);

	unsigned int	_size;
	T				*_arrayPtr;

};

# include "Array.tpp"

#endif
