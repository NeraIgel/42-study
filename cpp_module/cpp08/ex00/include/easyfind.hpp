/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:21:22 by heha              #+#    #+#             */
/*   Updated: 2023/01/12 15:32:07 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <limits>
# include <sstream>
# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typedef typename T::value_type	value_type;
	typedef typename T::iterator	iterator;

	if (std::numeric_limits<value_type>::min() != std::numeric_limits<int>::min() ||
			std::numeric_limits<value_type>::max() != std::numeric_limits<int>::max())
	{
		throw std::runtime_error("The container's value_type is not integer.");
	}

	iterator	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
	{
		std::ostringstream	oss;
		oss << "The container does not contain the value " << value;
		throw std::runtime_error(oss.str());
	}
	return (iter);
}

#endif
