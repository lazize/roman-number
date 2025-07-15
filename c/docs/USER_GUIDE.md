# User Guide

## Installation

### Prerequisites

- GCC compiler
- Make utility
- Git (for cloning)

### Building the Project

1. **Clone the repository**:
   ```bash
   git clone <repository-url>
   cd c-demo-make
   ```

2. **Build the project**:
   ```bash
   make
   ```

3. **Verify installation**:
   ```bash
   make test
   ```

## Using the Command Line Tool

### Basic Usage

Run the demo program:
```bash
make run
```

This will display conversions for several Roman numerals:
```
Roman Numeral Converter
======================
IV = 4 (PASS)
IX = 9 (PASS)
LVIII = 58 (PASS)
MCMXC = 1990 (PASS)
MMCDXLIV = 2444 (PASS)
I = 1 (PASS)
 = 0 (PASS)
```

### Running Tests

Execute the test suite:
```bash
make test
```

## Using the Library

### Including in Your Project

1. **Copy the source files**:
   - `src/roman.h`
   - `src/roman.c`

2. **Include the header**:
   ```c
   #include "roman.h"
   ```

3. **Compile with your project**:
   ```bash
   gcc your_file.c roman.c -o your_program
   ```

### Basic Example

```c
#include <stdio.h>
#include "roman.h"

int main() {
    const char* roman_nums[] = {"IV", "IX", "XLIV", "MCMXC"};
    
    for (int i = 0; i < 4; i++) {
        int decimal = roman_to_decimal(roman_nums[i]);
        printf("%s = %d\n", roman_nums[i], decimal);
    }
    
    return 0;
}
```

## Roman Numeral Rules

### Basic Symbols

| Symbol | Value | Description |
|--------|-------|-------------|
| I      | 1     | One |
| V      | 5     | Five |
| X      | 10    | Ten |
| L      | 50    | Fifty |
| C      | 100   | One hundred |
| D      | 500   | Five hundred |
| M      | 1000  | One thousand |

### Combination Rules

1. **Addition**: When smaller numerals follow larger ones, add them
   - VI = 5 + 1 = 6
   - XV = 10 + 5 = 15

2. **Subtraction**: When smaller numerals precede larger ones, subtract them
   - IV = 5 - 1 = 4
   - IX = 10 - 1 = 9
   - XL = 50 - 10 = 40

### Valid Subtractive Combinations

- I before V or X (IV = 4, IX = 9)
- X before L or C (XL = 40, XC = 90)
- C before D or M (CD = 400, CM = 900)

## Error Handling

The library handles various error conditions:

- **NULL input**: Returns 0
- **Empty string**: Returns 0
- **Invalid characters**: Treated as 0 value
- **Mixed valid/invalid**: Processes valid parts only

## Limitations

- Maximum supported value: 3999 (MMMCMXCIX)
- Case-sensitive: Only uppercase Roman numerals
- No validation of proper Roman numeral formation rules

## Troubleshooting

### Build Issues

**Error**: `gcc: command not found`
- **Solution**: Install GCC compiler

**Error**: `make: command not found`
- **Solution**: Install Make utility

### Runtime Issues

**Unexpected results**:
- Verify input uses uppercase letters only
- Check for invalid characters in input
- Ensure proper null termination of strings