/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:30:16 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 16:08:59 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

static void	doAnimalTest(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
}

static void	doAnimalTest2(void)
{
	Cat	*i = new Cat();
	Cat	*j = new Cat();

	i->getBrainPtr()->operator[](0) = "idea1";
	j->getBrainPtr()->operator[](0) = "idea2";
	std::cout << i->getBrainPtr()->operator[](0) << std::endl;
	std::cout << j->getBrainPtr()->operator[](0) << std::endl;

	*j = *i;
	std::cout << j->getBrainPtr()->operator[](0) << std::endl;

	delete i;
	std::cout << j->getBrainPtr()->operator[](0) << std::endl;

	*j = *j;
	std::cout << j->getBrainPtr()->operator[](0) << std::endl;

	delete j;
	std::cout << std::endl;
}

static void	doAnimalTest3(void)
{
	static const std::size_t	NumOfAnimals = 4;
	Animal						*animalPtrs[NumOfAnimals];

	for (std::size_t i = 0; i < NumOfAnimals; ++i)
	{
		if (i % 2 == 0)
			animalPtrs[i] = new Dog();
		else
			animalPtrs[i] = new Cat();
	}
	std::cout << std::endl;

	for (std::size_t i = 0; i < NumOfAnimals; ++i)
		animalPtrs[i]->makeSound();
	std::cout << std::endl;

	for (std::size_t i = 0; i < NumOfAnimals; ++i)
		delete animalPtrs[i];
	std::cout << std::endl;
}

static void	doAnimalTest4(void)
{
	const Animal* meta = new Animal();
	meta->makeSound();
	delete meta;
	std::cout << std::endl;
}

static void	leakCheck(void)
{
	std::system("leaks --list -- a.out");
}

int	main(void)
{
	doAnimalTest();
	doAnimalTest2();
	doAnimalTest3();
	doAnimalTest4();
	leakCheck();
	return (EXIT_SUCCESS);
}
