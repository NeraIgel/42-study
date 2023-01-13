/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:26:52 by heha              #+#    #+#             */
/*   Updated: 2022/12/20 21:45:45 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"

static void	doClapTrapTest(void)
{
	ClapTrap	anonymous1;
	ClapTrap	anonymous2(anonymous1);

	anonymous2 = anonymous1;
}

static void	doClapTrapTest(const std::string& source, const std::string& target, unsigned int damageAmount, unsigned int repairAmount)
{
	std::cout << std::endl;

	ClapTrap	robot(source);

	for (std::size_t i = 0; i < 10; ++i)
	{
		robot.attack(target);
		robot.takeDamage(damageAmount);
		robot.beRepaired(repairAmount);
	}
}

int	main(void)
{
	doClapTrapTest();
	doClapTrapTest("A", "B", 2, 4);
	doClapTrapTest("C", "D", 4, 2);
	doClapTrapTest("E", "F", 0, 0);
	doClapTrapTest("G", "H", 10, 10);
	return (EXIT_SUCCESS);
}
