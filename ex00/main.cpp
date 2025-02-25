/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:20:46 by deryacar          #+#    #+#             */
/*   Updated: 2025/02/25 19:20:46 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int ac, char* av[])
{
    if (ac != 2) {
        cout << "Error: Argument Error!" << endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
