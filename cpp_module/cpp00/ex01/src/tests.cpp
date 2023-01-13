/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:30:03 by heha              #+#    #+#             */
/*   Updated: 2022/11/11 16:17:16 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	cmd;

	while (pb.extract(cmd))
		pb.perform(cmd);
	return (EXIT_SUCCESS);
}
