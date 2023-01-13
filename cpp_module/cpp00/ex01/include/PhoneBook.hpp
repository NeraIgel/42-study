/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:34:55 by heha              #+#    #+#             */
/*   Updated: 2022/11/11 16:17:11 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

// ************************************************************************** //
//                              PhoneBook Class                               //
// ************************************************************************** //

# include <string>
# include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook& rhs);
	PhoneBook& operator=(const PhoneBook& rhs);

	bool	extract(std::string& cmd);
	void	perform(const std::string& cmd);

private:
	void	_operationAdd(void);
	void	_operationSearch(void) const;

	static const size_t	_NumOfContacts = 8U;
	Contact				_contacts[_NumOfContacts];
	size_t				_countContacts;
	size_t				_appendIdx;

};

#endif
