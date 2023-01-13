/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:09:27 by heha              #+#    #+#             */
/*   Updated: 2022/12/26 21:38:05 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include "DiamondTrap.hpp"

static void	doDiamondTrapTest(void)
{
	DiamondTrap	anonymous1;
	DiamondTrap	anonymous2(anonymous1);

	anonymous2 = anonymous1;
}

static void	doDiamondTrapTest(const std::string& source, const std::string& target, unsigned int damageAmount, unsigned int repairAmount)
{
	std::cout << std::endl;

	DiamondTrap	robot(source);

	robot.attack(target);
	robot.takeDamage(damageAmount);
	robot.beRepaired(repairAmount);
	robot.whoAmI();
}

static void	doDiamondTrapTest(const std::string& source1, const std::string& target1, const std::string& source2, const std::string& target2)
{
	std::cout << std::endl;

	ClapTrap	robot1(source1);
	DiamondTrap	robot2(source2);
	ClapTrap	*pr1 = &robot1;
	ClapTrap	*pr2 = &robot2;

	pr1->attack(target1);
	pr1->takeDamage(1);
	pr2->attack(target2);
	pr2->takeDamage(1);

	ScavTrap	*psr2 = &robot2;
	psr2->attack(target2);
	psr2->takeDamage(1);

	FragTrap	*pfr2 = &robot2;
	pfr2->attack(target2);
	pfr2->takeDamage(1);
}

int	main(void)
{
	doDiamondTrapTest();
	doDiamondTrapTest("A", "B", 20, 40);
	doDiamondTrapTest("I", "J", "K", "L");
	return (EXIT_SUCCESS);
}
