#include "roman.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int get_roman_value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int roman_to_decimal(const char* roman) {
    if (!roman) return 0;

    int result = 0;
    int len = strlen(roman);

    for (int i = 0; i < len; i++) {
        int current = get_roman_value(roman[i]);
        int next = (i + 1 < len) ? get_roman_value(roman[i + 1]) : 0;

        if (current < next) {
            result -= current;
        } else {
            result += current;
        }
    }

    return result;
}

char* decimal_to_roman(int decimal) {
    if (decimal <= 0 || decimal > 3999) {
        return NULL; // Roman numerals can't represent 0 or negative numbers, and traditionally only go up to 3999 (MMMCMXCIX)
    }

    // Maximum length needed for the largest number (3999 = MMMCMXCIX) plus null terminator
    char* result = (char*)malloc(16 * sizeof(char));
    if (!result) return NULL;

    result[0] = '\0'; // Initialize as empty string

    // Define value-symbol pairs in descending order
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // Build the Roman numeral
    for (int i = 0; i < 13; i++) {
        while (decimal >= values[i]) {
            strcat(result, symbols[i]);
            decimal -= values[i];
        }
    }

    return result;
}
