/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:55:22 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/13 15:36:29 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <class T> Array<T>::Array() : size_(0)
{
	elements_ = new T[size_];
}

template <class T> Array<T>::Array(unsigned int n) : size_(n)
{
	elements_ = new T[n];
	for (unsigned int i = 0; i < n; i++)
		elements_[i] = T();
}

template <class T> Array<T>::Array(const Array &base)
{
	size_ = base.size_;
	elements_ = new T[size_];
	for (unsigned int i = 0; i < size_; i++)
		elements_[i] = base.elements_[i];
}

template <class T> Array<T> &Array<T>::operator=(const Array &base)
{
	if (this != &base)
	{
		size_ = base.size_;
		elements_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			elements_[i] = base.elements_[i];
	}
	return (*this);
}

template <class T> Array<T>::~Array()
{
	if (elements_)
		delete [] elements_;
}

template <class T> T&Array<T>::operator[](unsigned int i)
{
	if (i >= size_)
		throw OutOfBoundsException();
	return (elements_[i]);
}

template <class T> unsigned int	Array<T>::size() const
{
	return (size_);
}

#endif