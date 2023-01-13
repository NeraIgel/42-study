/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:51:44 by heha              #+#    #+#             */
/*   Updated: 2023/01/10 12:51:54 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T>
void	iter(T const * const array, std::size_t length, void (*f)(const T&))
{
	for (std::size_t i = 0; i < length; ++i)
	{
		f(array[i]);
	}
}

template <typename T>
void	iter(T * const array, std::size_t length, void (*f)(T&))
{
	for (std::size_t i = 0; i < length; ++i)
	{
		f(array[i]);
	}
}

template <typename T>
void	show(const T& val)
{
	std::cout << val << std::endl;
}

template <typename T>
void	replace(T& val)
{
	val = 0;
}

#endif
