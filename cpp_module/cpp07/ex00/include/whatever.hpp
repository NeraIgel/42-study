/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:47:43 by heha              #+#    #+#             */
/*   Updated: 2023/01/10 12:47:51 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T	temp(a);
	a = b;
	b = temp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

#endif
