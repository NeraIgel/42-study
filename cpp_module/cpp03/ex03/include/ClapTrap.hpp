/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:03:31 by heha              #+#    #+#             */
/*   Updated: 2022/12/24 21:09:50 by heha             ###   ########.fr       */
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
	virtual ~ClapTrap();

	void	attack(const std::string& target);
	void	attack(const char *pTarget);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	virtual std::string	_createAttackLogString(const std::string& target) const;
	virtual std::string	_createAttackLogString(const char *pTarget) const;
	virtual std::string	_createTakeDamageLogString(unsigned int amount) const;
	virtual std::string	_createBeRepairedLogString(unsigned int amount) const;
	std::string	_createClapTrapLogString(const std::string& logInfo) const;
	std::string	_createClapTrapLogString(const char *pLogInfo) const;

	virtual unsigned int	_maxHitPoints() const;

protected:
	explicit ClapTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int damage);
	explicit ClapTrap(const char *pName, unsigned int hp, unsigned int ep, unsigned int damage);

	void	_logClapTrap(const std::string& logInfo) const;
	void	_logClapTrap(const char *pLogInfo) const;

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
