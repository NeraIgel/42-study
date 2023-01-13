/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:09:56 by heha              #+#    #+#             */
/*   Updated: 2022/11/04 15:55:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <string>
#include <cstdlib>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		std::string	str;
		for (int i = 1; i < argc; ++i)
			for (size_t j = 0U; argv[i][j] != '\0'; ++j)
				str.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j]))));
		std::cout << str << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (EXIT_SUCCESS);
}
