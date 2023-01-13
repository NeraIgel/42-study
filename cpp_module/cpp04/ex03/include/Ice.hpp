/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:06:18 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 20:09:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

// ************************************************************************** //
//                                 Ice Class                                  //
// ************************************************************************** //

# include "AMateria.hpp"

class Ice : public AMateria {

public:
	explicit Ice();
	Ice(const Ice& rhs);
	Ice& operator=(const Ice& rhs);
	~Ice();

	virtual AMateria	*clone() const;
	virtual void		use(ICharacter& target);

};

#endif
