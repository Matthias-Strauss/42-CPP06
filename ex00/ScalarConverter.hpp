/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:34:54 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/17 18:54:15 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>

bool isSpecial(const std::string &str);
void printImpossible();
void printChar(double d);
void printInt(double d);
void printFloat(double d);
void printDouble(double d);
void handleCharInput(char c);

class ScalarConverter
{
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter &) = delete;
    ScalarConverter &operator=(const ScalarConverter &) = delete;
    ~ScalarConverter() = delete;
};

#endif
