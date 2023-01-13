/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:52:07 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 13:14:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

// ************************************************************************** //
//                             WrongAnimal Class                              //
// ************************************************************************** //

# include <string>

class WrongAnimal {

public:
	explicit WrongAnimal();
	WrongAnimal(const WrongAnimal& rhs);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	~WrongAnimal();

	const std::string&	getType() const;

	void	makeSound() const;

protected:
	explicit WrongAnimal(const std::string& type);
	explicit WrongAnimal(const char *pType);

	void	_logWrongAnimal(const std::string& logInfo) const;
	void	_logWrongAnimal(const char *pLogInfo) const;

	std::string	_type;

private:
	static std::string	_createWrongAnimalLogString(const std::string& logInfo);
	static std::string	_createWrongAnimalLogString(const char *pLogInfo);
	const char	*_createMakeSoundLogString() const;

};

#endif
