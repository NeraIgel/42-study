/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:57:47 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 20:02:34 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

// ************************************************************************** //
//                                 Cure Class                                 //
// ************************************************************************** //

# include "AMateria.hpp"

class Cure : public AMateria {

public:
	explicit Cure();
	Cure(const Cure& rhs);
	Cure& operator=(const Cure& rhs);
	~Cure();

	virtual AMateria	*clone() const;
	virtual void		use(ICharacter& target);

};

#endif
