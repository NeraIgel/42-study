/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:55:12 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:15:36 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

// ************************************************************************** //
//                              WrongCat Class                                //
// ************************************************************************** //

# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	explicit WrongCat();
	WrongCat(const WrongCat& rhs);
	WrongCat& operator=(const WrongCat& rhs);
	~WrongCat();

private:
	static std::string	_createWrongCatLogString(const std::string& logInfo);
	static std::string	_createWrongCatLogString(const char *pLogInfo);
	const char	*_createMakeSoundLogString() const;

};

#endif
