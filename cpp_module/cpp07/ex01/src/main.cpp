/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:52:02 by heha              #+#    #+#             */
/*   Updated: 2023/01/10 12:55:31 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include "iter.hpp"

static void	doIterTest1(void)
{
	static const std::size_t	NumOfArray = 5;
	char						array[NumOfArray] = { 'a', 'b', 'c', 'd', 'e' };

	std::cout << "[char test]" << std::endl;
	iter(array, NumOfArray, show<char>);
	iter(array, NumOfArray, replace<char>);
	iter(array, NumOfArray, show<char>);
}

static void	doIterTest2(void)
{
	static const std::size_t	NumOfArray = 5;
	int							array[NumOfArray] = { 1, 2, 3, 4, 5 };

	std::cout << '\n' << "[int test]" << std::endl;
	iter(array, NumOfArray, show<int>);
	iter(array, NumOfArray, replace<int>);
	iter(array, NumOfArray, show<int>);
}

static void	doIterTest3(void)
{
	static const std::size_t	NumOfArray = 5;
	double						array[NumOfArray] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

	std::cout << '\n' << "[double test]" << std::endl;
	iter(array, NumOfArray, show<double>);
	iter(array, NumOfArray, replace<double>);
	iter(array, NumOfArray, show<double>);
}

static void	doIterTest4(void)
{
	static const std::size_t	NumOfArray = 5;
	std::string					array[NumOfArray] = { "test1", "test2", "test3", "test4", "test5" };

	std::cout << '\n' << "[std::string test]" << std::endl;
	iter(array, NumOfArray, show<std::string>);
}

int	main(void)
{
	doIterTest1();
	doIterTest2();
	doIterTest3();
	doIterTest4();
	return (EXIT_SUCCESS);
}
