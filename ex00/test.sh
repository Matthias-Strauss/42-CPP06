#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    echo -e "\n${GREEN}Testing: $1${NC}"
    ./convert "$1"
}

# Compile the program
echo "Compiling program..."
make re

# Test cases
echo -e "\n${GREEN}=== Testing Char Literals ===${NC}"
run_test "'a'"
run_test "'*'"
run_test "'0'"

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
run_test "42f"  # Missing decimal point
run_test "42.0"  # Missing f suffix for float 