/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:50:31 by heha              #+#    #+#             */
/*   Updated: 2022/11/16 18:33:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REPLACE_HPP
# define REPLACE_HPP

// ************************************************************************** //
//                               Replace Class                                //
// ************************************************************************** //

# include <string>

class Replace {

public:
	explicit Replace(const std::string& filename);
	explicit Replace(const Replace& rhs);
	Replace& operator=(const Replace& rhs);
	~Replace();

	bool	execute(const std::string& s1, const std::string& s2) const;

private:
	std::string	_filename;

};

#endif
