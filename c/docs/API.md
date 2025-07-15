# API Documentation

## Functions

### `roman_to_decimal`

Converts a Roman numeral string to its decimal integer equivalent.

```c
int roman_to_decimal(const char* roman);
```

#### Parameters

- `roman` - Pointer to null-terminated string containing Roman numeral
  - Must contain only valid Roman characters: I, V, X, L, C, D, M
  - Case-sensitive (uppercase only)
  - Can be NULL (returns 0)

#### Return Value

- **Type**: `int`
- **Range**: 0 to 3999 (maximum valid Roman numeral)
- **Special cases**:
  - Returns `0` if input is NULL
  - Returns `0` if input is empty string
  - Invalid characters are treated as 0 value

#### Examples

```c
// Basic conversions
roman_to_decimal("I");        // Returns 1
roman_to_decimal("V");        // Returns 5
roman_to_decimal("X");        // Returns 10

// Subtractive notation
roman_to_decimal("IV");       // Returns 4
roman_to_decimal("IX");       // Returns 9
roman_to_decimal("XL");       // Returns 40
roman_to_decimal("XC");       // Returns 90
roman_to_decimal("CD");       // Returns 400
roman_to_decimal("CM");       // Returns 900

// Complex numbers
roman_to_decimal("XIV");      // Returns 14
roman_to_decimal("LVIII");    // Returns 58
roman_to_decimal("MCMXC");    // Returns 1990
roman_to_decimal("MMCDXLIV"); // Returns 2444

// Error cases
roman_to_decimal(NULL);       // Returns 0
roman_to_decimal("");         // Returns 0
roman_to_decimal("ABC");      // Returns 0
```

#### Algorithm

The function uses a single-pass algorithm that:

1. Iterates through each character in the string
2. Gets the decimal value of current and next characters
3. If current < next, subtracts current value (subtractive case)
4. Otherwise, adds current value to result
5. Returns the accumulated result

#### Time Complexity

- **O(n)** where n is the length of the input string

#### Space Complexity

- **O(1)** constant space usage

## Internal Functions

### `get_roman_value` (static)

Maps individual Roman characters to their decimal values.

```c
static int get_roman_value(char c);
```

- **Internal function** - not exposed in public API
- Returns 0 for invalid characters
- Used by `roman_to_decimal` for character-to-value mapping