/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:38:24 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/19 16:16:25 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : storage_(0), nums_(0)
{
}

Span::Span(unsigned int N) : storage_(N), nums_(std::vector<int>())
{
}

Span::Span(Span const &base)
{
	this->storage_ = base.storage_;
	this->nums_.clear();
	this->nums_ = base.nums_;
}

Span &Span::operator=(Span const &base)
{
	if (this != &base)
	{
		this->storage_ = base.storage_;
		this->nums_.clear();
		this->nums_ = base.nums_;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (this->storage_ > nums_.size())
		nums_.push_back(number);
	else
		throw MaxStorageException();
}

int	Span::shortestSpan(void)
{
	if (nums_.size() < 2)
		throw NoSpanException();
	int	possibleSpan = INT_MAX;
	std::vector<int> temp_sort(nums_);
	std::sort(temp_sort.begin(), temp_sort.end());
	for (std::vector<int>::iterator iter = temp_sort.begin(); iter != temp_sort.end() - 1; ++iter)
	{
		int	temp = *(iter + 1) - *iter;
		if (possibleSpan > temp)
			possibleSpan = temp;
	}
	if (possibleSpan == INT_MAX || possibleSpan == 0)
		throw NoSpanException();
	return (possibleSpan);
/*	First off it checks the size of the vector that belongs to this class.
	If there isn't at least 2 numbers, it throws an exception.
	It then creates:
		- a variable for the biggest span possible within the INT variables.
		- a copy of the vector to be sorted next.
		- an iterator of a vector.
		- a temp variable to store and compare the value of the positions of
		(iterator + 1) and iterator.
	The smallest difference between every two values is considered the shortest span*/
}

int	Span::longestSpan(void)
{
	if (nums_.size() < 2)
		throw NoSpanException();
	int	min = *std::min_element(nums_.begin(), nums_.end());
	int max = *std::max_element(nums_.begin(), nums_.end());
	if (min == max)
		throw NoSpanException();
	else
		return (max - min);
}
