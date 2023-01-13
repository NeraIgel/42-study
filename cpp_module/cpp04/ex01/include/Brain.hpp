/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:54:10 by heha              #+#    #+#             */
/*   Updated: 2023/01/02 16:39:30 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

// ************************************************************************** //
//                                Brain Class                                 //
// ************************************************************************** //

# include <string>

class Brain {

public:
	explicit Brain();
	Brain(const Brain& rhs);
	Brain& operator=(const Brain& rhs);
	~Brain();

	std::string&		operator[](std::size_t position);
	const std::string&	operator[](std::size_t position) const;

private:
	static void	_logBrain(const std::string& logInfo);
	static void	_logBrain(const char *pLogInfo);
	static void	_error(const std::string& errorMsg);
	static void	_error(const char *pErrorMsg);

	static const std::size_t	_NumOfIdeas = 100;
	std::string					_ideasArray[_NumOfIdeas];

};

#endif
