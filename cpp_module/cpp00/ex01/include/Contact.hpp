/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:51:13 by heha              #+#    #+#             */
/*   Updated: 2022/11/10 16:30:53 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

# include <string>

class Contact {

public:
	Contact();
	~Contact();
	Contact(const Contact& rhs);
	Contact& operator=(const Contact& rhs);

	void	makeContactInfos(void);
	void	displayContactInfos(size_t displayIndex) const;

private:
	void	_clearContactInfos(void);

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif
