/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:04:38 by heha              #+#    #+#             */
/*   Updated: 2023/01/13 12:19:10 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

// ************************************************************************** //
//                              MutantStack Class                             //
// ************************************************************************** //

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	explicit MutantStack();
	MutantStack(const MutantStack& rhs);
	MutantStack& operator=(const MutantStack& rhs);
	~MutantStack();

	iterator				begin();
	const_iterator			begin() const;

	iterator				end();
	const_iterator			end() const;

	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;

	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

};

# include "MutantStack.tpp"

#endif
