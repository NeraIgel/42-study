/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:49:19 by heha              #+#    #+#             */
/*   Updated: 2022/11/14 19:28:18 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //

# include <string>

class Zombie {

public:
	Zombie();
	explicit Zombie(const std::string& name);
	explicit Zombie(const Zombie& rhs);
	Zombie& operator=(const Zombie& rhs);
	~Zombie();

	void	setName(const std::string& name);

	void	announce(void) const;

private:
	std::string	_name;

};

Zombie	*zombieHorde(int N, std::string name);

#endif
