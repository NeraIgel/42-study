/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:43:53 by heha              #+#    #+#             */
/*   Updated: 2022/11/14 16:01:33 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Zombie.hpp"

static void	zombieHordeTest(int N, const std::string& name)
{
	Zombie	*pz = zombieHorde(N, name);
	if (pz)
	{
		for (int i = 0; i < N; ++i)
			pz[i].announce();
		delete [] pz;
	}
}

int	main(void)
{
	zombieHordeTest(-1, "horde1");
	zombieHordeTest(0, "horde2");
	zombieHordeTest(1, "horde3");
	zombieHordeTest(42, "horde4");
	return (EXIT_SUCCESS);
}
