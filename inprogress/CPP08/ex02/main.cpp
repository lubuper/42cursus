/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:56:49 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/20 20:13:09 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl; // should print 17

    mstack.pop();

    std::cout << mstack.size() << std::endl; // should print 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::it it1 = mstack.iterator_begin();
    MutantStack<int>::it it2 = mstack.iterator_end();

    while (it1 != it2) {
        std::cout << *it1 << std::endl;
        ++it1;
    }

    return 0;
}