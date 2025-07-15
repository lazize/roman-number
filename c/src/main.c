#include <stdio.h>
#include "roman.h"

const char* validate_expected(int actual, int expected);

int main(void) {
    const char* test_cases[] = {"IV", "IX", "LVIII", "MCMXC", "MMCDXLIV", "I", ""};
    int expected[] = {4, 9, 58, 1990, 2444, 1, 1};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Roman Numeral Converter\n");
    printf("======================\n");
    
    for (int i = 0; i < num_tests; i++) {
        int result = roman_to_decimal(test_cases[i]);
        printf("'%s' = %d (%s)\n", test_cases[i], result, validate_expected(result, expected[i]));
    }
    
    return 0;
}

const char* validate_expected(int actual, int expected) {
    if (actual == expected) {
        return "PASS";
    } else {
        return "FAIL";
    }
}
