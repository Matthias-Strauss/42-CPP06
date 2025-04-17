/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:34:54 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/17 16:41:33 by mstrauss         ###   ########.fr       */
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
