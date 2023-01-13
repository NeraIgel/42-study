/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:07:10 by heha              #+#    #+#             */
/*   Updated: 2022/11/16 17:23:21 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (2 == argc)
	{
		Harl	harl(argv[1]);

		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		harl.complain("GOOD");
	}
	else
		std::cout << "\033[30;1m" << "The number of arguments is invalid." << "\033[0m" << std::endl;
	return (EXIT_SUCCESS);
}
