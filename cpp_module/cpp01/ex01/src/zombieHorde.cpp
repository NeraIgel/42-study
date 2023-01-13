/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:43:02 by heha              #+#    #+#             */
/*   Updated: 2022/11/17 17:21:39 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "\033[31;1m" << "Requested allocation size error (" << N << ")." << "\033[0m" << std::endl;
		return (NULL);
	}
	else
	{
		Zombie	*pz = new Zombie[N];
		std::ostringstream	oss;
		for (int i = 0; i < N; ++i)
		{
			oss.str("");
			oss.clear();
			oss << name << '_' << i;
			pz[i].setName(oss.str());
		}
		return (pz);
	}
}
