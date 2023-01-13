/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:42:33 by heha              #+#    #+#             */
/*   Updated: 2022/12/26 20:18:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

// ************************************************************************** //
//                              ScavTrap Class                                //
// ************************************************************************** //

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	explicit ScavTrap(const std::string& name);
	explicit ScavTrap(const char *pName = "Anonymous");
	ScavTrap(const ScavTrap& rhs);
	ScavTrap& operator=(const ScavTrap& rhs);
	~ScavTrap();

	void	guardGate();

private:
	std::string	_createScavTrapLogString(const std::string& logInfo) const;
	std::string	_createScavTrapLogString(const char *pLogInfo) const;
	std::string	_createGuardGateLogString() const;

protected:
	virtual std::string	_createAttackLogString(const std::string& target) const;
	virtual std::string	_createAttackLogString(const char *pTarget) const;
	virtual std::string	_createTakeDamageLogString(unsigned int amount) const;
	virtual std::string	_createBeRepairedLogString(unsigned int amount) const;

	virtual unsigned int	_maxHitPoints() const;

};

#endif
