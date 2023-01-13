/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:51:15 by heha              #+#    #+#             */
/*   Updated: 2022/12/24 21:51:53 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include "FragTrap.hpp"

static void	doFragTrapTest(void)
{
	FragTrap	anonymous1;
	FragTrap	anonymous2(anonymous1);

	anonymous2 = anonymous1;
}

static void	doFragTrapTest(const std::string& source, const std::string& target, unsigned int damageAmount, unsigned int repairAmount)
{
	std::cout << std::endl;

	FragTrap	robot(source);

	robot.attack(target);
	robot.takeDamage(damageAmount);
	robot.beRepaired(repairAmount);
	robot.highFivesGuys();
}

static void	doFragTrapTest(const std::string& source1, const std::string& target1, const std::string& source2, const std::string& target2)
{
	std::cout << std::endl;

	ClapTrap	robot1(source1);
	FragTrap	robot2(source2);
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
	doFragTrapTest();
	doFragTrapTest("A", "B", 20, 40);
	doFragTrapTest("C", "D", 40, 20);
	doFragTrapTest("E", "F", 0, 0);
	doFragTrapTest("G", "H", 100, 100);
	doFragTrapTest("I", "J", "K", "L");
	return (EXIT_SUCCESS);
}
