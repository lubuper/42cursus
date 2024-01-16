/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:35:10 by lde-sous          #+#    #+#             */
/*   Updated: 2024/01/15 19:16:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <climits>
# include <algorithm>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <deque>
# include <sys/time.h>

class	PmergeMe
{
	private:
		std::vector<int> vectorArr_;
		std::deque<int> dequeArr_;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &base);
		PmergeMe	&operator=(PmergeMe const &base);
		PmergeMe(int ac, char **av);
		void	sort_and_compare(void);
		void	vector_split_sort(std::vector<int> &vec);
		void	deque_split_sort(std::deque<int> &deq);
		void	vector_merge(std::vector<int> &first, std::vector<int> &second, std::vector<int> &original);
		void	deque_merge(std::deque<int> &first, std::deque<int> &second, std::deque<int> &original);
};

#endif