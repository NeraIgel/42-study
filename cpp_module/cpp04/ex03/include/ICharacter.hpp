/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:09:47 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 16:51:59 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

// ************************************************************************** //
//                              ICharacter Class                              //
// ************************************************************************** //

# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter {

public:
	virtual ~ICharacter()	{}

	virtual const std::string&	getName() const = 0;

	virtual void	equip(AMateria *m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;

};

#endif
