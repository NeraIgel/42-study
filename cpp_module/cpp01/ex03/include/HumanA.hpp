/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:59:42 by heha              #+#    #+#             */
/*   Updated: 2022/11/14 18:07:59 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

// ************************************************************************** //
//                               HumanA Class                                 //
// ************************************************************************** //

#include <string>
#include "Weapon.hpp"

class HumanA {

public:
	explicit HumanA(const std::string& name, Weapon& weapon);
	~HumanA();

	void	attack(void) const;

private:
	HumanA(const HumanA& rhs);
	HumanA&	operator=(const HumanA& rhs);

	std::string	_name;
	Weapon&		_rWeapon;

};

#endif
