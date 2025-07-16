#include <stdio.h>
#include <stdlib.h>

#include "roman.h"

const char* validate_expected(int actual, int expected);

int main(void) {
    const char* test_cases[] = {"IV", "IX", "LVIII", "MCMXC", "MMCDXLIV", "I", ""};
    int expected[] = {4, 9, 58, 1990, 2444, 1, 0};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Roman Numeral Converter\n");
    printf("======================\n");
    
    printf("Roman to Decimal:\n");
    for (int i = 0; i < num_tests; i++) {
        int result = roman_to_decimal(test_cases[i]);
        printf("'%s' = %d (%s)\n", test_cases[i], result, validate_expected(result, expected[i]));
    }
    
    printf("\nDecimal to Roman:\n");
    int decimal_test_cases[] = {4, 9, 58, 1990, 2444, 1, 3999};
    int decimal_num_tests = sizeof(decimal_test_cases) / sizeof(decimal_test_cases[0]);
    
    for (int i = 0; i < decimal_num_tests; i++) {
        char* roman = decimal_to_roman(decimal_test_cases[i]);
        if (roman) {
            printf("%d = '%s'\n", decimal_test_cases[i], roman);
            free(roman); // Free the allocated memory
        } else {
            printf("%d = Invalid for Roman numeral conversion\n", decimal_test_cases[i]);
        }
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
