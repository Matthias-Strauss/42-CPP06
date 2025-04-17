/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:34:53 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/17 16:52:32 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// use errno?

void ScalarConverter::convert(const std::string &str)
{
    // check if empty str
    if (str.empty())
    {
        // print impossible?
        return 1;
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
    return 0;
}