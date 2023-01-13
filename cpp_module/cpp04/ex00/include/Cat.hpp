/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:49:11 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:14:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

// ************************************************************************** //
//                                 Cat Class                                  //
// ************************************************************************** //

# include <string>
# include "Animal.hpp"

class Cat : public Animal {

public:
	explicit Cat();
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	~Cat();

private:
	static std::string	_createCatLogString(const std::string& logInfo);
	static std::string	_createCatLogString(const char *pLogInfo);
	virtual const char	*_createMakeSoundLogString() const;

};

#endif
