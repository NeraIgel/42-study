/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:48:29 by heha              #+#    #+#             */
/*   Updated: 2022/12/26 21:35:33 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

// ************************************************************************** //
//                             DiamondTrap Class                              //
// ************************************************************************** //

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:
	explicit DiamondTrap(const std::string& name = std::string("Anonymous"));
	DiamondTrap(const DiamondTrap& rhs);
	DiamondTrap& operator=(const DiamondTrap& rhs);
	~DiamondTrap();

	void	whoAmI();

private:
	virtual std::string	_createAttackLogString(const std::string& target) const;
	virtual std::string	_createAttackLogString(const char *pTarget) const;
	virtual std::string	_createTakeDamageLogString(unsigned int amount) const;
	virtual std::string	_createBeRepairedLogString(unsigned int amount) const;
	std::string	_createDiamondTrapLogString(const std::string& logInfo) const;
	std::string	_createDiamondTrapLogString(const char *pLogInfo) const;
	std::string	_createWhoAmILogString() const;

	virtual unsigned int	_maxHitPoints() const;

	std::string	_name;

};

#endif
