/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:48:54 by heha              #+#    #+#             */
/*   Updated: 2022/12/26 21:08:57 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

// ************************************************************************** //
//                              FragTrap Class                                //
// ************************************************************************** //

# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:
	explicit FragTrap(const std::string& name);
	explicit FragTrap(const char *pName = "Anonymous");
	FragTrap(const FragTrap& rhs);
	FragTrap& operator=(const FragTrap& rhs);
	~FragTrap();

	void	highFivesGuys();

private:
	std::string	_createFragTrapLogString(const std::string& logInfo) const;
	std::string	_createFragTrapLogString(const char *pLogInfo) const;
	std::string	_createHighFivesGuysLogString() const;

protected:
	virtual unsigned int	_maxHitPoints() const;

};

#endif
