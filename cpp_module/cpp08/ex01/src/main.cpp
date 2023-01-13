/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:45:27 by heha              #+#    #+#             */
/*   Updated: 2023/01/12 21:29:42 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "Span.hpp"

static void	doSpanTest(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void	doSpanTest(unsigned int N)
{
	std::cout << '\n' << "[ doSpanTest : " << N << " ]" << std::endl;
	try
	{
		Span	sp(N);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(19);
		sp.addNumber(21);
//		sp.addNumber(2147483647);
//		sp.addNumber(-2147483648);

		unsigned int	shortestSpan = sp.shortestSpan();
		unsigned int	longestSpan = sp.longestSpan();

		std::cout << "shortestSpan: " << shortestSpan << std::endl;
		std::cout << "longestSpan: " << longestSpan << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31;1mException:\033[0m " << e.what() << std::endl;
	}
}

static void	doSpanRangeTest(unsigned int N)
{
	std::cout << '\n' << "[ doSpanRangeTest : " << N << " ]" << std::endl;
	
	try
	{
		Span	sp(N);

//		sp.addNumber(1);
		sp.addNumber(sp.getBegin(), sp.getBegin() + N);

		unsigned int	shortestSpan = sp.shortestSpan();
		unsigned int	longestSpan = sp.longestSpan();

		if (N < 10)
			sp.showNumber();
		std::cout << "shortestSpan: " << shortestSpan << std::endl;
		std::cout << "longestSpan: " << longestSpan << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31;1mException:\033[0m " << e.what() << std::endl;
	}
}

int	main(void)
{
	doSpanTest();
	doSpanTest(0);
	doSpanTest(1);
	doSpanTest(2);
	doSpanTest(42);
//	doSpanRangeTest(0);
//	doSpanRangeTest(1);
//	doSpanRangeTest(2);
//	doSpanRangeTest(5);
//	doSpanRangeTest(10000);
	doSpanRangeTest(42000);
	return (EXIT_SUCCESS);
}
