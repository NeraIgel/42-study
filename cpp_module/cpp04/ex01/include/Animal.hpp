/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:31:52 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:12:24 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

// ************************************************************************** //
//                               Animal Class                                 //
// ************************************************************************** //

# include <string>

class Animal {

public:
	explicit Animal();
	Animal(const Animal& rhs);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal();

	const std::string&	getType() const;

	void	makeSound() const;

protected:
	explicit Animal(const std::string& type);
	explicit Animal(const char *pType);

	void	_logAnimal(const std::string& logInfo) const;
	void	_logAnimal(const char *pLogInfo) const;

	std::string	_type;

private:
	static std::string	_createAnimalLogString(const std::string& logInfo);
	static std::string	_createAnimalLogString(const char *pLogInfo);
	virtual const char	*_createMakeSoundLogString() const;

};

#endif
