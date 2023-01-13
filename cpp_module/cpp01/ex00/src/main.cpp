/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:03:52 by heha              #+#    #+#             */
/*   Updated: 2022/11/12 17:45:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*pz = newZombie("newZombie");
	Zombie	zb("localZombie");

	randomChump("randomZombie");
	pz->announce();
	zb.announce();
	delete pz;
	return (EXIT_SUCCESS);
}
