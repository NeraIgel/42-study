/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:49:19 by heha              #+#    #+#             */
/*   Updated: 2022/11/14 15:11:42 by heha             ###   ########.fr       */
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
	explicit Zombie(const std::string& name);
	explicit Zombie(const Zombie& rhs);
	Zombie& operator=(const Zombie& rhs);
	~Zombie();

	void	announce(void) const;

private:
	std::string	_name;

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
