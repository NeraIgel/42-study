/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:51:22 by heha              #+#    #+#             */
/*   Updated: 2022/11/16 17:10:35 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

// ************************************************************************** //
//                                 Harl Class                                 //
// ************************************************************************** //

#include <string>

class Harl {

public:
	enum HarlLevel { DEBUG, INFO, WARNING, ERROR, EXCEPTION };

	typedef void (Harl::*func_pointer_t)(void) const;

	struct MapStringToFunction {
		const char		*level;
		func_pointer_t	func;
	};

	explicit Harl(const std::string& minAllowedLevel = std::string("INFO"));
	explicit Harl(const Harl& rhs);
	Harl& operator=(const Harl& rhs);
	~Harl();

	void	complain(std::string level) const;

private:
	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;
	void	_exception(void) const;

	std::string	_minAllowedLevel;

};

#endif
