/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:49:27 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 16:54:09 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

// ************************************************************************** //
//                               AMateria Class                               //
// ************************************************************************** //

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {

public:
	explicit AMateria();
	explicit AMateria(const std::string& type);
	explicit AMateria(const char *pType);
	AMateria(const AMateria& rhs);
	AMateria& operator=(const AMateria& rhs);
	virtual ~AMateria();

	const std::string&	getType() const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter& target);

protected:
	static void	_error(const std::string& errorMsg);
	static void	_error(const char *pErrorMsg);

private:
	std::string	_type;

};

#endif
