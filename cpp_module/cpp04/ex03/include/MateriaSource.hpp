/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:57:13 by heha              #+#    #+#             */
/*   Updated: 2022/12/31 16:46:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

// ************************************************************************** //
//                             MateriaSource Class                            //
// ************************************************************************** //

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:
	explicit MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	MateriaSource& operator=(const MateriaSource& rhs);
	~MateriaSource();

	virtual void		learnMateria(AMateria *m);
	virtual AMateria	*createMateria(const std::string& type);

private:
	void	_initMateriaArray();
	void	_clearMateriaArray();
	void	_copyMateriaArray(const MateriaSource& rhs);

	static const int	_NumOfMateria = 4;
	AMateria			*_materiaArray[_NumOfMateria];

};

#endif
