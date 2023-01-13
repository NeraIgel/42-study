/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:46:10 by heha              #+#    #+#             */
/*   Updated: 2023/01/06 20:53:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include "Data.hpp"

static void	showDataMember(const Data& data)
{
	std::cout << "n: " << data.n << std::endl;
	std::cout << "f: " << data.f << std::endl;
	std::cout << "d: " << data.d << std::endl;
	std::cout << "str: " << data.str << std::endl;
}

static uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

static Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data	data = { -1, 1.2f, 42.3, "string" };

	std::cout << "[before]" << std::endl;
	showDataMember(data);

	uintptr_t	raw = serialize(&data);
	Data		*ptr = deserialize(raw);

	std::cout << "\n" << "[after]" << std::endl;
	showDataMember(*ptr);
	return (EXIT_SUCCESS);
}
