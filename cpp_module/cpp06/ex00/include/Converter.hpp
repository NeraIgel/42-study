/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:01:21 by heha              #+#    #+#             */
/*   Updated: 2023/01/06 15:54:21 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONVERTER_HPP
# define CONVERTER_HPP

// ************************************************************************** //
//                               Converter Class                              //
// ************************************************************************** //

# include <string>

class Converter {

public:
	explicit Converter(const std::string& input);
	explicit Converter(const char *pInput);
	~Converter();

	void	toChar() const;
	void	toInt() const;
	void	toFloat() const;
	void	toDouble() const;

private:
	Converter();
	Converter(const Converter& rhs);
	Converter& operator=(const Converter& rhs);

	void	_replaceInputString();
	void	_convertToNumber();

	std::string	_input;
	double		_number;
	bool		_isPossibleConversion;

};

#endif
