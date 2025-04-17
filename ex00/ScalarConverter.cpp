/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:34:53 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/17 17:11:26 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// use errno?
void printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

bool isSpecial(const std::string &str)
{
    bool isSpecial = false;

    if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
    {
    }
    else if (str == "-inf" || str == "-inff")
    {
    }
    else if (str == "nan" || str == "nanf")
    {
    }
    else
    {
        isSpecial = false;
    }
}

void ScalarConverter::convert(const std::string &str)
{
    if (str.empty())
    {
        std::cout << "Empty input!" << std::endl;
        printImpossible();
        return;
    }

    if (ifSpecial(str))
    {
        return;
    }

    // convert using strtod
    // -> check errno for errors
    // -> check if leftover characters -> invalid input

    // if (endptr moved by strtod) && no errno && endptr == \0     ==> success

    // --> print

    // else handle Character

    // else ERROR
    else
        printImpossible();
    return 0;
}