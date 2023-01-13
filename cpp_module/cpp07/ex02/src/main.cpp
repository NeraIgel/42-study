/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:18:37 by heha              #+#    #+#             */
/*   Updated: 2023/01/10 17:10:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "Array.hpp"

#define MAX_VAL 750

static void	doArrayTest(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
			std::exit(EXIT_FAILURE);
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

static void	showIntArrayMembers(const Array<int>& array, const char *pName)
{
	std::cout << "[ " << pName << " ]" << std::endl;
	unsigned int	size = array.size();

	std::cout << "size: " << size << std::endl;
	if (size)
	{
		std::cout << " >> " << std::flush;
		for (unsigned int i = 0; i < size - 1; ++i)
			std::cout << array[i] << ", ";
		std::cout << array[size - 1] << std::endl;
	}
}

static void	doArrayTest(unsigned int n)
{
	std::cout << std::endl;

	Array<int>	numbers(n);
	for (unsigned int i = 0; i < n; ++i)
		numbers[i] = i + 1;
	showIntArrayMembers(numbers, "numbers");

	Array<int>	copy1(numbers);
	showIntArrayMembers(copy1, "copy1");

	Array<int>	copy2;
	showIntArrayMembers(copy2, "copy2 before");
	copy2 = copy1;
	showIntArrayMembers(copy2, "copy2 after");

	Array<int>	*pCopy3 = new Array<int>(n);
	for (unsigned int i = 0; i < n; ++i)
		(*pCopy3)[i] = -(i + 1);
	showIntArrayMembers(*pCopy3, "copy3");
	copy2 = *pCopy3;
	showIntArrayMembers(copy2, "copy2 before deleting copy3");
	delete pCopy3;
	showIntArrayMembers(copy2, "copy2 after deleting copy3");
}

static void	leakCheck(void)
{
	std::cout << std::endl;
	std::system("leaks --list -- a.out");
}

int	main(void)
{
	try
	{
		doArrayTest();
		doArrayTest(0);
		doArrayTest(1);
		doArrayTest(42);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	leakCheck();
	return (EXIT_SUCCESS);
}
