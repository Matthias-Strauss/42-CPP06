#!/bin/bash
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.sh                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:14:39 by mstrauss          #+#    #+#             */
/*   Updated: 2025/03/22 14:39:44 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

run_test() {
    echo -e "\n${GREEN}Testing: $1${NC}"
    ./convert "$1"
}

echo "Compiling program..."
make re

echo -e "\n${GREEN}=== Testing Char Literals ===${NC}"
run_test a
run_test 'a'
run_test '*'
run_test '0'

echo -e "\n${GREEN}=== Testing Int Literals ===${NC}"
run_test "0"
run_test "-42"
run_test "42"

echo -e "\n${GREEN}=== Testing Float Literals ===${NC}"
run_test "0.0f"
run_test "-4.2f"
run_test "4.2f"

echo -e "\n${GREEN}=== Testing Float Pseudo Literals ===${NC}"
run_test "-inff"
run_test "+inff"
run_test "nanf"

echo -e "\n${GREEN}=== Testing Double Literals ===${NC}"
run_test "0.0"
run_test "-4.2"
run_test "4.2"

echo -e "\n${GREEN}=== Testing Double Pseudo Literals ===${NC}"
run_test "-inf"
run_test "+inf"
run_test "nan"

echo -e "\n${GREEN}=== Testing Edge Cases ===${NC}"
run_test "0.0f"
run_test "0.0"
run_test "0"
run_test "'0'"

echo -e "\n${GREEN}=== Testing Invalid Inputs ===${NC}"
run_test "invalid"
run_test "123.456.789"
run_test ""
run_test "42a"