/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:01:07 by heha              #+#    #+#             */
/*   Updated: 2022/12/24 21:46:29 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include "ScavTrap.hpp"

static void	doScavTrapTest(void)
{
	ScavTrap	anonymous1;
	ScavTrap	anonymous2(anonymous1);

	anonymous2 = anonymous1;
}

static void	doScavTrapTest(const std::string& source, const std::string& target, unsigned int damageAmount, unsigned int repairAmount)
{
	std::cout << std::endl;

	ScavTrap	robot(source);

	robot.attack(target);
	robot.takeDamage(damageAmount);
	robot.beRepaired(repairAmount);
	robot.guardGate();
}

static void	doScavTrapTest(const std::string& source1, const std::string& target1, const std::string& source2, const std::string& target2)
{
	std::cout << std::endl;

	ClapTrap	robot1(source1);
	ScavTrap	robot2(source2);
	ClapTrap&	rr1 = robot1;
	ClapTrap&	rr2 = robot2;
	ClapTrap	*pr1 = &robot1;
	ClapTrap	*pr2 = &robot2;

	rr1.attack(target1);
	rr2.attack(target2);
	pr1->attack(target1);
	pr2->attack(target2);
	pr1->takeDamage(1);
	pr2->takeDamage(1);
}

int	main(void)
{
	doScavTrapTest();
	doScavTrapTest("A", "B", 20, 40);
	doScavTrapTest("C", "D", 40, 20);
	doScavTrapTest("E", "F", 0, 0);
	doScavTrapTest("G", "H", 100, 100);
	doScavTrapTest("I", "J", "K", "L");
	return (EXIT_SUCCESS);
}
