/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:40:34 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:13:31 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

// ************************************************************************** //
//                                 Dog Class                                  //
// ************************************************************************** //

# include <string>
# include "Animal.hpp"

class Dog : public Animal {

public:
	explicit Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	~Dog();

private:
	static std::string	_createDogLogString(const std::string& logInfo);
	static std::string	_createDogLogString(const char *pLogInfo);
	virtual const char	*_createMakeSoundLogString() const;

};

#endif
