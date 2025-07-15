# Developer Guide

## Project Architecture

### Directory Structure

```
c-demo-make/
├── src/                 # Source code
│   ├── main.c          # Demo application
│   ├── roman.c         # Core conversion logic
│   ├── roman.h         # Public API header
│   └── test_roman.c    # Test suite
├── obj/                # Compiled object files (generated)
├── bin/                # Executable files (generated)
├── docs/               # Documentation
├── Makefile           # Build configuration
└── README.md          # Project overview
```

### Core Components

1. **roman.h**: Public API interface
2. **roman.c**: Implementation of conversion algorithm
3. **main.c**: Command-line demo application
4. **test_roman.c**: Comprehensive test suite

## Development Setup

### Prerequisites

- GCC 4.9+ (C99 support required)
- Make 3.81+
- Git for version control

### Initial Setup

```bash
git clone <repository-url>
cd c-demo-make
make clean  # Clean any existing builds
make test   # Verify everything works
```

## Build System

### Makefile Targets

| Target | Description |
|--------|-------------|
| `all` | Build main program (default) |
| `debug` | Build with debug flags (-g -O0) |
| `release` | Build with optimization (-O2) |
| `test` | Build and run test suite |
| `run` | Build and run main program |
| `clean` | Remove object files and executables |
| `distclean` | Remove all generated files and directories |
| `help` | Show available targets |

### Compiler Flags

- **Standard**: `-Wall -Wextra -std=c99`
- **Debug**: `-g -O0` (debugging symbols, no optimization)
- **Release**: `-O2` (optimization level 2)

## Code Organization

### Algorithm Design

The Roman numeral converter uses a single-pass algorithm:

```c
// Pseudocode
for each character in input:
    current_value = get_value(current_char)
    next_value = get_value(next_char)
    
    if current_value < next_value:
        result -= current_value  // Subtractive case
    else:
        result += current_value  // Additive case
```

### Key Design Decisions

1. **Static helper function**: `get_roman_value()` is file-scoped
2. **Null safety**: All functions handle NULL input gracefully
3. **Single responsibility**: Each function has one clear purpose
4. **Minimal dependencies**: Only uses standard C library

## Testing Strategy

### Test Categories

1. **Null/Empty Input**: Edge cases and error conditions
2. **Single Characters**: Basic symbol validation
3. **Additive Cases**: Standard Roman numeral addition
4. **Subtractive Cases**: All valid subtractive combinations
5. **Complex Numbers**: Real-world examples
6. **Invalid Input**: Error handling verification
7. **Edge Cases**: Non-standard but valid combinations

### Running Tests

```bash
# Run all tests
make test

# Build test executable only
make bin/test_roman

# Run specific test manually
./bin/test_roman
```

### Adding New Tests

1. Edit `src/test_roman.c`
2. Add test function following naming convention: `test_<category>()`
3. Use `assert()` for validation
4. Call new test function in `main()`

Example:
```c
void test_new_feature() {
    assert(roman_to_decimal("MMXX") == 2020);
    printf("✓ New feature test passed\n");
}
```

## Contributing

### Code Style

- **Indentation**: 4 spaces (no tabs)
- **Braces**: K&R style
- **Naming**: snake_case for functions and variables
- **Comments**: Minimal, focus on why not what

### Adding Features

1. **Create feature branch**:
   ```bash
   git checkout -b feature/new-feature
   ```

2. **Implement changes**:
   - Update source code
   - Add tests
   - Update documentation

3. **Verify changes**:
   ```bash
   make clean
   make test
   make run
   ```

4. **Submit changes**:
   ```bash
   git add .
   git commit -m "Add new feature"
   git push origin feature/new-feature
   ```

### Performance Considerations

- **Time Complexity**: O(n) where n is string length
- **Space Complexity**: O(1) constant space
- **Memory Usage**: No dynamic allocation
- **String Operations**: Single `strlen()` call per conversion

### Security Considerations

- **Buffer Safety**: No buffer operations, only character access
- **Input Validation**: Handles NULL and invalid input safely
- **Integer Overflow**: Maximum value 3999 prevents overflow

## Debugging

### Debug Build

```bash
make debug
gdb ./bin/program
```

### Common Issues

1. **Segmentation Fault**: Check for NULL pointer access
2. **Wrong Results**: Verify Roman numeral formation rules
3. **Build Errors**: Ensure GCC and Make are installed

### Debugging Tools

- **GDB**: Step-through debugging
- **Valgrind**: Memory leak detection
- **Static Analysis**: Use `-Wall -Wextra` flags

## Release Process

1. **Update version numbers** in documentation
2. **Run full test suite**: `make test`
3. **Build release version**: `make release`
4. **Update CHANGELOG.md**
5. **Create git tag**: `git tag v1.0.0`
6. **Push changes**: `git push --tags`