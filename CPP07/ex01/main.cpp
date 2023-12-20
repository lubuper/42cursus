/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:41:55 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/12 10:41:02 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) 
{
    int     arr[] = {10, 12, 33, 46, 57};
    size_t  len = sizeof(arr) / sizeof(int);
    char    cstr[] = {'C', 'H', 'A', 'R', '\0'};
    std::string str = "abcdefghij";
    
    
    iter<int>(arr, len, printit);
    std::cout << std::endl;
    
    iter<char>(cstr, 5, printit);
    std::cout << std::endl;
    
    iter<const char>(str.c_str(), str.length(), printit);
    std::cout << std::endl;
    
    iter<int>(arr, len, fun);
    std::cout << std::endl;
    iter<int>(arr, len, printit);
    std::cout << std::endl;
    iter<char>(cstr, len, fun);
    std::cout << std::endl;
    iter<char>(cstr, 5, printit);
    std::cout << std::endl;
}