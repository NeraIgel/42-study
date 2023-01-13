/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:40:34 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:22:35 by heha             ###   ########.fr       */
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
# include "Brain.hpp"

class Dog : public Animal {

public:
	explicit Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	~Dog();

	Brain	*getBrainPtr() const;

private:
	static std::string	_createDogLogString(const std::string& logInfo);
	static std::string	_createDogLogString(const char *pLogInfo);
	virtual const char	*_createMakeSoundLogString() const;
	void	_error(const std::string& errorMsg);
	void	_error(const char *pErrorMsg);
	void	_copyDog(const Dog& rhs);

	Brain	*_brainPtr;

};

#endif
