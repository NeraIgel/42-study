/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:01:05 by heha              #+#    #+#             */
/*   Updated: 2022/11/14 16:12:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>

int	main(void)
{
	const std::string	str("HI THIS IS BRAIN");
	const std::string&	stringREF = str;
	const std::string	*stringPTR;
	stringPTR = &str;

	std::cout << "address of string : " << &str << std::endl;
	std::cout << "address of stringREF : " << &stringREF << std::endl;
	std::cout << "address of stringPTR : " << stringPTR << std::endl;
	std::cout << std::endl;

	std::cout << "value of string : " << str << std::endl;
	std::cout << "value of stringREF : " << stringREF << std::endl;
	std::cout << "value of stringPTR : " << *stringPTR << std::endl;
	return (EXIT_SUCCESS);
}
