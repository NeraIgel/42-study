/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:12:45 by heha              #+#    #+#             */
/*   Updated: 2022/12/30 20:33:46 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP

// ************************************************************************** //
//                            IMateriaSource Class                            //
// ************************************************************************** //

# include <string>
# include "AMateria.hpp"

class IMateriaSource {

public:
	virtual ~IMateriaSource()	{}

	virtual void		learnMateria(AMateria *m) = 0;
	virtual AMateria	*createMateria(const std::string& type) = 0;

};

#endif
