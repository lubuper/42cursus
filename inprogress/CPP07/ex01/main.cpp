/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:41:55 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/07 19:25:26 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printit(int i) 
{
    std::cout << i << std::endl;
}

int main() 
{
    int arr[] = {10, 12, 33, 46, 57};
    size_t len = sizeof(arr) / sizeof(int);
    iter(arr, len, printit);

    return 0;
}