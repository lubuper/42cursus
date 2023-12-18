/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:38:24 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/18 14:37:08 by lde-sous         ###   ########.fr       */
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
		this->storage_ = base	.storage_;
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
	if (this->storage_ < nums_.size())
		nums_.push_back(number);
}

int	Span::shortestSpan(int number)
{
	
}

int	Span::longestSpan()
{
	
}
