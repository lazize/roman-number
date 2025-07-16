#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "roman.h"

void test_null_input() {
    assert(roman_to_decimal(NULL) == 0);
    printf("✓ NULL input test passed\n");
}

void test_empty_string() {
    assert(roman_to_decimal("") == 0);
    printf("✓ Empty string test passed\n");
}

void test_single_characters() {
    assert(roman_to_decimal("I") == 1);
    assert(roman_to_decimal("V") == 5);
    assert(roman_to_decimal("X") == 10);
    assert(roman_to_decimal("L") == 50);
    assert(roman_to_decimal("C") == 100);
    assert(roman_to_decimal("D") == 500);
    assert(roman_to_decimal("M") == 1000);
    printf("✓ Single character tests passed\n");
}

void test_additive_cases() {
    assert(roman_to_decimal("II") == 2);
    assert(roman_to_decimal("III") == 3);
    assert(roman_to_decimal("VI") == 6);
    assert(roman_to_decimal("VII") == 7);
    assert(roman_to_decimal("VIII") == 8);
    assert(roman_to_decimal("XI") == 11);
    assert(roman_to_decimal("XV") == 15);
    assert(roman_to_decimal("XX") == 20);
    assert(roman_to_decimal("LX") == 60);
    assert(roman_to_decimal("CX") == 110);
    printf("✓ Additive cases tests passed\n");
}

void test_subtractive_cases() {
    assert(roman_to_decimal("IV") == 4);
    assert(roman_to_decimal("IX") == 9);
    assert(roman_to_decimal("XL") == 40);
    assert(roman_to_decimal("XC") == 90);
    assert(roman_to_decimal("CD") == 400);
    assert(roman_to_decimal("CM") == 900);
    printf("✓ Subtractive cases tests passed\n");
}

void test_complex_numbers() {
    assert(roman_to_decimal("XIV") == 14);
    assert(roman_to_decimal("XXIV") == 24);
    assert(roman_to_decimal("XLIV") == 44);
    assert(roman_to_decimal("LVIII") == 58);
    assert(roman_to_decimal("XCIV") == 94);
    assert(roman_to_decimal("CDXLIV") == 444);
    assert(roman_to_decimal("MCMXC") == 1990);
    assert(roman_to_decimal("MMCDXLIV") == 2444);
    assert(roman_to_decimal("MMMCMXCIX") == 3999);
    printf("✓ Complex numbers tests passed\n");
}

void test_invalid_characters() {
    assert(roman_to_decimal("A") == 0);
    assert(roman_to_decimal("Z") == 0);
    assert(roman_to_decimal("123") == 0);
    assert(roman_to_decimal("IVA") == 4);  // Valid part + invalid
    printf("✓ Invalid characters tests passed\n");
}

void test_edge_cases() {
    assert(roman_to_decimal("IIII") == 4);    // Non-standard but valid
    assert(roman_to_decimal("VV") == 10);     // Non-standard but valid
    assert(roman_to_decimal("IXIX") == 18);   // Multiple subtractive
    assert(roman_to_decimal("IVIV") == 8);    // Multiple subtractive
    printf("✓ Edge cases tests passed\n");
}

void test_decimal_to_roman() {
    char* result;
    
    result = decimal_to_roman(1);
    assert(strcmp(result, "I") == 0);
    free(result);
    
    result = decimal_to_roman(4);
    assert(strcmp(result, "IV") == 0);
    free(result);
    
    result = decimal_to_roman(9);
    assert(strcmp(result, "IX") == 0);
    free(result);
    
    result = decimal_to_roman(58);
    assert(strcmp(result, "LVIII") == 0);
    free(result);
    
    result = decimal_to_roman(1990);
    assert(strcmp(result, "MCMXC") == 0);
    free(result);
    
    result = decimal_to_roman(2444);
    assert(strcmp(result, "MMCDXLIV") == 0);
    free(result);
    
    result = decimal_to_roman(3999);
    assert(strcmp(result, "MMMCMXCIX") == 0);
    free(result);
    
    // Test invalid inputs
    assert(decimal_to_roman(0) == NULL);
    assert(decimal_to_roman(-1) == NULL);
    assert(decimal_to_roman(4000) == NULL);
    
    printf("✓ Decimal to Roman tests passed\n");
}

int main(void) {
    printf("Running Roman Numeral Tests\n");
    printf("==========================\n");
    
    test_null_input();
    test_empty_string();
    test_single_characters();
    test_additive_cases();
    test_subtractive_cases();
    test_complex_numbers();
    test_invalid_characters();
    test_edge_cases();
    test_decimal_to_roman();
    
    printf("\n🎉 All tests passed!\n");
    return 0;
}