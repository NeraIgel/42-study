/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:36:44 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 16:47:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

// ************************************************************************** //
//                               Character Class                              //
// ************************************************************************** //

# include "ICharacter.hpp"

class Character : public ICharacter {

public:
	explicit Character(const std::string& name);
	explicit Character(const char *pName = "Anonymous");
	Character(const Character& rhs);
	Character& operator=(const Character& rhs);
	~Character();

	virtual const std::string&	getName() const;

	virtual void	equip(AMateria *m);
	virtual void	unequip(int idx);
	virtual void	use(int idx, ICharacter& target);

private:
	void	_initInventoryArray();
	void	_clearInventoryArray();
	void	_copyInventoryArray(const Character& rhs);

	std::string			_name;
	static const int	_NumOfInventory = 4;
	AMateria			*_inventoryArray[_NumOfInventory];

};

#endif
