/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:03:31 by heha              #+#    #+#             */
/*   Updated: 2022/12/22 15:35:42 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

// ************************************************************************** //
//                              ClapTrap Class                                //
// ************************************************************************** //

# include <string>

class ClapTrap {

public:
	explicit ClapTrap(const std::string& name);
	explicit ClapTrap(const char *pName = "Anonymous");
	ClapTrap(const ClapTrap& rhs);
	ClapTrap& operator=(const ClapTrap& rhs);
	~ClapTrap();

	void	attack(const std::string& target);
	void	attack(const char *pTarget);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string	_createAttackLogString(const std::string& target) const;
	std::string	_createAttackLogString(const char *pTarget) const;
	std::string	_createTakeDamageLogString(unsigned int amount) const;
	std::string	_createBeRepairedLogString(unsigned int amount) const;

	void	_logClapTrap(const std::string& logInfo) const;
	void	_logClapTrap(const char *pLogInfo) const;

	static const unsigned int	_maxHitPoints = 10;

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
