/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:35:10 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/30 11:39:41 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <algorithm>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <deque>

class	PmergeMe
{
	private:
		;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &base);
		PmergeMe	&operator=(PmergeMe const &base);
};

#endif