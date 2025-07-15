#include "roman.h"
#include <string.h>

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