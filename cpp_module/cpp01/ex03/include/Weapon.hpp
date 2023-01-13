/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:39:58 by heha              #+#    #+#             */
/*   Updated: 2022/11/17 11:20:34 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

// ************************************************************************** //
//                               Weapon Class                                 //
// ************************************************************************** //

# include <string>

class Weapon {

public:
	explicit Weapon(const std::string& type);
	Weapon(const Weapon& rhs);
	Weapon& operator=(const Weapon& rhs);
	~Weapon();

	const std::string&	getType(void) const;
	void				setType(const std::string& type);

private:
	std::string	_type;

};

#endif
