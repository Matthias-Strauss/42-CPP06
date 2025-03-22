/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:35:00 by mstrauss          #+#    #+#             */
/*   Updated: 2025/03/22 15:17:07 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <stdexcept>
#include <cmath>

ScalarConverter::ScalarConverter() = default;
ScalarConverter::~ScalarConverter() = default;
ScalarConverter::ScalarConverter(const ScalarConverter &) = default;
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) = default;

[[nodiscard]] static constexpr bool isChar(std::string_view literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

[[nodiscard]] static bool isInt(std::string_view literal)
{
    try
    {
        size_t pos;
        std::stoi(std::string(literal), &pos);
        return pos == literal.length();
    }
    catch (const std::exception &)
    {
        return false;
    }
}

[[nodiscard]] static bool isFloat(std::string_view literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    try
    {
        size_t pos;
        std::stof(std::string(literal), &pos);
        return pos == literal.length() - 1 && literal[pos] == 'f';
    }
    catch (const std::exception &)
    {
        return false;
    }
}

[[nodiscard]] static bool isDouble(std::string_view literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    try
    {
        size_t pos;
        std::stod(std::string(literal), &pos);
        return pos == literal.length();
    }
    catch (const std::exception &)
    {
        return false;
    }
}

[[nodiscard]] static constexpr bool isDisplayable(char c)
{
    return (c >= 32 && c <= 126);
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isChar(literal))
    {
        char c = literal[1];
        std::cout << "char: " << (isDisplayable(c) ? std::string(1, c) : "Non displayable") << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (isInt(literal))
    {
        try
        {
            int i = std::stoi(literal);
            std::cout << "char: " << (isDisplayable(static_cast<char>(i)) ? std::string(1, static_cast<char>(i)) : "Non displayable") << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
        }
        catch (const std::exception &)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
    else if (isFloat(literal))
    {
        float f;
        if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else
            f = std::stof(literal);

        if (isnan(f))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else
        {
            std::cout << "char: " << (isDisplayable(static_cast<char>(f)) ? std::string(1, static_cast<char>(f)) : "Non displayable") << std::endl;
            std::cout << "int: " << (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max() ? static_cast<int>(f) : std::numeric_limits<int>::min()) << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        }
    }
    else if (isDouble(literal))
    {
        double d;
        if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else if (literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else
            d = std::stod(literal);

        if (isnan(d))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else
        {
            std::cout << "char: " << (isDisplayable(static_cast<char>(d)) ? std::string(1, static_cast<char>(d)) : "Non displayable") << std::endl;
            std::cout << "int: " << (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() ? static_cast<int>(d) : std::numeric_limits<int>::min()) << std::endl;
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid input format" << std::endl;
    }
}
