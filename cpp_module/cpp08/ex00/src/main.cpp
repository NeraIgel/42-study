/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:56:07 by heha              #+#    #+#             */
/*   Updated: 2023/01/12 13:39:55 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <deque>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include "easyfind.hpp"

#define MAX_COUNT	5

static void	doListTest(int value)
{
	std::list<int>	list(MAX_COUNT, -1);

	try
	{
		std::list<int>::iterator	iter = easyfind(list, value);
		std::cout << "list result: " << "The container contains the value " << value << " (index: " << std::distance(list.begin(), iter) << ')' << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "\033[31;1m" << "list exception: " << "\033[0m" << e.what() << std::endl;
	}
}

static void	doDequeTest(int value)
{
	std::deque<int>	deque(MAX_COUNT, 0);

	try
	{
		std::deque<int>::iterator	iter = easyfind(deque, value);
		std::cout << "deque result: " << "The container contains the value " << value << " (index: " << std::distance(deque.begin(), iter) << ')' << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "\033[31;1m" << "deque exception: " << "\033[0m" << e.what() << std::endl;
	}
}

static void	doVectorTest(int value)
{
	std::vector<int>	vector(MAX_COUNT - 1, 1);
	vector.push_back(42);

	try
	{
		std::vector<int>::iterator	iter = easyfind(vector, value);
		std::cout << "vector result: " << "The container contains the value " << value << " (index: " << std::distance(vector.begin(), iter) << ')' << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "\033[31;1m" << "vector exception: " << "\033[0m" << e.what() << std::endl;
	}
}

static void	doSequenceContainersTest(int value)
{
	std::cout << "[ doSequenceContainersTest ]" << std::endl;
	doListTest(value);
	doDequeTest(value);
	doVectorTest(value);
	std::cout << std::endl;
}

int	main(void)
{
	doSequenceContainersTest(-1);
	doSequenceContainersTest(0);
	doSequenceContainersTest(1);
	doSequenceContainersTest(42);
	return (EXIT_SUCCESS);
}
