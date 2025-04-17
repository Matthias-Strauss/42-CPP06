/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:34:53 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/17 18:03:53 by mstrauss         ###   ########.fr       */
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
    bool isSpecial = true;
    double dbl;
    float flt;

    if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
    {
        dbl = std::numeric_limits<double>::infinity();
        flt = std::numeric_limits<float>::infinity();
    }
    else if (str == "-inf" || str == "-inff")
    {
        dbl = -std::numeric_limits<double>::infinity();
        flt = -std::numeric_limits<float>::infinity();
    }
    else if (str == "nan" || str == "nanf")
    {
        dbl = std::numeric_limits<double>::quiet_NaN();
        flt = std::numeric_limits<float>::quiet_NaN();
    }
    else
    {
        isSpecial = false;
    }
    if (isSpecial)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << flt << "f" << std::endl;
        std::cout << "double: " << dbl << std::endl;
        // might be needed for signed -inf, +inf, maybe possible without (handled by cout)
        // std::cout << "float: " << (std::isnan(flt) ? "nanf" : (flt > 0 ? "+inff" : "-inff")) << std::endl;
        // std::cout << "double: " << (std::isnan(dbl) ? "nan" : (dbl > 0 ? "+inf" : "-inf")) << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::convert(const std::string &str)
{
    if (str.empty())
    {
        std::cout << "Empty input!" << std::endl;
        printImpossible();
        return;
    }

    if (isSpecial(str))
        return;

    errno = 0;
    // convert using strtod
    char *endptr = nullptr;
    double d = std::strtod(str.c_str(), &endptr);

    // -> check if chars processed
    bool validNum = (endptr != str.c_str());
    // -> check errno for errors
    bool overflow = (errno == ERANGE);
    // -> check if leftover characters -> invalid input
    bool checkEnd = (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0'));

    // if (endptr moved by strtod) && no errno && endptr == \0     ==> success
    if (validNum && !overflow && checkEnd)
    {
        // --> print
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
    }
    // else handle Character
    else if (str.length() == 1 && !std::isdigit(str[0]) && !validNum)
    {
        handleCharInput();
    }
    // else ERROR
    else
        printImpossible();
    return;
}