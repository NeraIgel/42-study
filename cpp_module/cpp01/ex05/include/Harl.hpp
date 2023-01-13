/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:51:22 by heha              #+#    #+#             */
/*   Updated: 2022/11/17 12:25:01 by heha             ###   ########.fr       */
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
	Harl();
	explicit Harl(const Harl& rhs);
	Harl& operator=(const Harl& rhs);
	~Harl();

	void	complain(std::string level) const;

private:
	typedef void (Harl::*func_pointer_t)(void) const;

	struct MapStringToFunction {
		const char		*level;
		func_pointer_t	func;
	};

	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;
	void	_exception(void) const;

};

#endif
