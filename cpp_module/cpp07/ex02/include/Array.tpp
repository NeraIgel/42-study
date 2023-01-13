/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:00:06 by heha              #+#    #+#             */
/*   Updated: 2023/01/10 16:50:10 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                               Constructors                                 //
// ************************************************************************** //

template <typename T>
Array<T>::Array()
	: _size(0), _arrayPtr(NULL)
{}

template <typename T>
Array<T>::Array(unsigned int n)
	: _size(n), _arrayPtr(NULL)
{
	_initArray();
}

template <typename T>
Array<T>::Array(const Array<T>& rhs)
	: _size(0), _arrayPtr(NULL)
{
	_copyArray(rhs);
}

// ************************************************************************** //
//                                Properties                                  //
// ************************************************************************** //

template <typename T>
unsigned int	Array<T>::size() const	{ return(_size); }

// ************************************************************************** //
//                                Operations                                  //
// ************************************************************************** //

template <typename T>
T&	Array<T>::operator[](unsigned int position)
{
	return (
			const_cast<T&>(
				static_cast<const Array<T>&>(
					*this)[position]
				)
		   );
}

template <typename T>
const T&	Array<T>::operator[](unsigned int position) const
{
	if (position >= size())
		throw OutOfRangeException();
	return (_arrayPtr[position]);
}

// ************************************************************************** //
//                              Implementation                                //
// ************************************************************************** //

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		_copyArray(rhs);
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	_clearArray();
}

template <typename T>
const char	*Array<T>::OutOfRangeException::what() const throw()
{
	return ("\033[31;1mException:\033[0m The requested index is out of range.");
}

template <typename T>
void	Array<T>::_initArray()
{
	if (_size)
		_arrayPtr = new T [_size];
}

template <typename T>
void	Array<T>::_clearArray()
{
	delete [] _arrayPtr;
	_arrayPtr = NULL;
	_size = 0;
}

template <typename T>
void	Array<T>::_copyArray(const Array<T>& rhs)
{
	T	*pOrig = _arrayPtr;
	
	_arrayPtr = new T [rhs.size()];
	_size = rhs.size();
	for (unsigned int i = 0; i < _size; ++i)
		_arrayPtr[i] = rhs._arrayPtr[i];
	delete [] pOrig;
}
