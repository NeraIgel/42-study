/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:06:41 by heha              #+#    #+#             */
/*   Updated: 2023/01/07 13:47:17 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "Base.hpp"

static void	leakCheck(void)
{
	std::cout << std::endl;
	std::system("leaks --list -- a.out");
}

int	main(void)
{
	try
	{
		Base	*pb = generate();

		identify(pb);
		identify(*pb);

		delete pb;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31;1mException:\033[0m " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	leakCheck();
	return (EXIT_SUCCESS);
}
