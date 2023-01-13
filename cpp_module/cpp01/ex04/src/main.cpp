/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:44:26 by heha              #+#    #+#             */
/*   Updated: 2022/11/16 18:32:08 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Replace.hpp"

int	main(int argc, char *argv[])
{
	bool	result = true;

	if (4 == argc)
	{
		Replace	replacer(argv[1]);
		result = replacer.execute(argv[2], argv[3]);
	}
	else
		std::cout << "\033[30;1m" << "[ The number of arguments is invalid. ]" << "\033[0m" << std::endl;
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
