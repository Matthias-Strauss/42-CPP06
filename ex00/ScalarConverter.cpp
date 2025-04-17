/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:34:53 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/17 18:52:56 by mstrauss         ###   ########.fr       */
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

void printChar(double d)
{
    std::cout << "char: ";
    char c = static_cast<char>(d);
    if (std::isprint(c))
        std::cout << c << std::endl;
    if (d < 0 || d > 255)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void printInt(double d)
{
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

void printFloat(double d)
{
    std::cout << "float: ";
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        float f = static_cast<float>(d);
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
}

void printDouble(double d)
{
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
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

void handleCharInput(char c)
{
    int i;
    float f;
    double d;

    std::cout << "char: ";
    if (std::isprint(c))
        std::cout << c << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
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
        // WE SHOULD HAVE ONLY VALID NUMBERS IN THIS CASE< NO NEED TO CHECK FOR SPECIALS!!!!
        // --> print
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
        // std::cout << "DEBUG" << std::endl;
    }
    // else handle Character
    else if (str.length() == 1 && !std::isdigit(str[0]) && !validNum)
    {
        handleCharInput(*(str.c_str()));
    }
    // else ERROR
    else
        printImpossible();
    return;
    (void)d;
}