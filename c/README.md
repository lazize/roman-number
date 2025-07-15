# Roman Numeral Converter

A C library and command-line tool for converting Roman numerals to decimal numbers.

## Features

- Convert Roman numerals (I, V, X, L, C, D, M) to decimal integers
- Handle subtractive notation (IV=4, IX=9, XL=40, etc.)
- Comprehensive error handling for invalid input
- Full test suite with edge case coverage

## Quick Start

```bash
# Clone and build
git clone <repository-url>
cd c-demo-make
make

# Run the demo
make run

# Run tests
make test
```

## Example Usage

```c
#include "roman.h"

int result = roman_to_decimal("MCMXC");  // Returns 1990
printf("%d\n", result);
```

## Supported Roman Numerals

| Symbol | Value |
|--------|-------|
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

## Build Requirements

- GCC compiler
- Make
- Standard C library

## Project Structure

```
c-demo-make/
├── src/           # Source files
├── obj/           # Object files (generated)
├── bin/           # Executables (generated)
├── Makefile       # Build configuration
└── README.md      # This file
```

## License

MIT License - see LICENSE file for details.