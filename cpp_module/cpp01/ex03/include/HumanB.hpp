/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:28:56 by heha              #+#    #+#             */
/*   Updated: 2022/11/14 18:09:19 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

// ************************************************************************** //
//                               HumanB Class                                 //
// ************************************************************************** //

#include <string>
#include "Weapon.hpp"

class HumanB {

public:
	explicit HumanB(const std::string& name);
	~HumanB();

	void	setWeapon(Weapon& weapon);

	void	attack(void) const;

private:
	HumanB(const HumanB& rhs);
	HumanB&	operator=(const HumanB& rhs);

	std::string	_name;
	Weapon		*_pWeapon;

};

#endif
