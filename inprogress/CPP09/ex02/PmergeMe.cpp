/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:34:59 by lde-sous          #+#    #+#             */
/*   Updated: 2024/01/08 19:29:37 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{	
}

PmergeMe::~PmergeMe()
{	
}

PmergeMe::PmergeMe(PmergeMe const &base): vectorArr_(base.vectorArr_), dequeArr_(base.dequeArr_)
{	
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &base)
{
	if (this != &base)
	{
		vectorArr_ = base.vectorArr_;
		dequeArr_ = base.dequeArr_;
	}
	return (*this);
}

PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		vectorArr_.push_back(std::atoi(av[i]));
		dequeArr_.push_back(std::atoi(av[i]));
	}
}

void	PmergeMe::sort_and_compare(void)
{
	size_t	vecsize = vectorArr_.size();
	size_t	deqsize = dequeArr_.size();
	std::cout << "Before ";
	for (size_t i = 0; i < vecsize; i++)
	{
		std::cout << vectorArr_[i];
		if (i != vecsize - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	clock_t	start1 = clock();
	vector_split_sort(vectorArr_);
	clock_t	end1 = clock();
	clock_t	start2 = clock();
	deque_split_sort(dequeArr_);
	clock_t	end2 = clock();
	std::cout << "After ";
	for (size_t i = 0; i < vecsize; i++)
	{
		std::cout << vectorArr_[i];
		if (i != vecsize - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	double vectorETA = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vecsize << " elements with std::vector: " << vectorETA << " s" << std::endl;
	double dequeETA = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << deqsize << " elements with std::deque: " << dequeETA << " s" << std::endl;
}

void	PmergeMe::vector_split_sort(std::vector<int> &vec)
{
	if (vec.size() == 1)
		return ;
	int	middle = vec.size() / 2;
	std::vector<int> first = std::vector<int>(vec.begin(), vec.begin() + middle);
	std::vector<int> second = std::vector<int>(vec.begin() + middle, vec.end());
	vector_split_sort(first);
	vector_split_sort(second);
	vector_merge(first, second, vec);
}

void	PmergeMe::deque_split_sort(std::deque<int> &deq)
{
	if (deq.size() == 1)
		return ;
	int	middle = deq.size() / 2;
	std::deque<int> first = std::deque<int>(deq.begin(), deq.begin() + middle);
	std::deque<int> second = std::deque<int>(deq.begin() + middle, deq.end());
	deque_split_sort(first);
	deque_split_sort(second);
	deque_merge(first, second, deq);	
}

void	PmergeMe::vector_merge(std::vector<int> &first, std::vector<int> &second, std::vector<int> &original)
{
	size_t	f = 0;
	size_t	s = 0;
	size_t	i = 0;
	while (f < first.size() && s < second.size())
	{
		if (first[f] < second[s])
			original[i++] = first[f++];
		else
			original[i++] = second[s++];
	}
	while (f < first.size())
		original[i++] = first[f++];
	while (s < second.size())
		original[i++] = second[s++];
}

void	PmergeMe::deque_merge(std::deque<int> &first, std::deque<int> &second, std::deque<int> &original)
{
	size_t	f = 0;
	size_t	s = 0;
	size_t	i = 0;
	while (f < first.size() && s < second.size())
	{
		if (first[f] < second[s])
			original[i++] = first[f++];
		else
			original[i++] = second[s++];
	}
	while (f < first.size())
		original[i++] = first[f++];
	while (s < second.size())
		original[i++] = second[s++];	
}
