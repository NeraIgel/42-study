/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:54:49 by heha              #+#    #+#             */
/*   Updated: 2023/01/06 20:35:33 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "Converter.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		try
		{
			Converter	converter(argv[1]);

			converter.toChar();
			converter.toInt();
			converter.toFloat();
			converter.toDouble();
		}
		catch (const std::exception& e)
		{
			std::cerr << "\033[31;1mException:\033[0m " << e.what() << std::endl;
			return (EXIT_FAILURE);
		}
	}
	else
		std::cerr << "\033[31;1mError:\033[0m invalid number of argument." << std::endl;
	return (EXIT_SUCCESS);
}
