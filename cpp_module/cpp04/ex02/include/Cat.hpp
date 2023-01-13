/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:49:11 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:24:51 by heha             ###   ########.fr       */
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
# include "Brain.hpp"

class Cat : public Animal {

public:
	explicit Cat();
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	~Cat();

	Brain	*getBrainPtr() const;

private:
	static std::string	_createCatLogString(const std::string& logInfo);
	static std::string	_createCatLogString(const char *pLogInfo);
	virtual const char	*_createMakeSoundLogString() const;
	void	_error(const std::string& errorMsg);
	void	_error(const char *pErrorMsg);
	void	_copyCat(const Cat& rhs);

	Brain	*_brainPtr;

};

#endif
