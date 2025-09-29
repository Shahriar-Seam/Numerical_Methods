# Numerical Methods Implementation

A comprehensive collection of numerical methods implementations in C++, Python, and C for solving various mathematical problems commonly encountered in computational mathematics and engineering.

## 📚 Overview

This repository contains implementations of fundamental numerical methods organized into different categories. The final, polished implementations can be found in the `Codes/All Methods/` directory, which serves as the main reference for all numerical algorithms.

## 🗂️ Repository Structure

```
Numerical_Methods/
├── Codes/
│   ├── All Methods/           # Final implementations (main reference)
│   │   ├── Common/           # Shared utilities and helper functions
│   │   ├── *.cpp             # C++ implementations
│   │   ├── *.py              # Python implementations
│   │   └── *.hpp             # Header files
│   ├── Class_1/              # Class exercises and examples
│   ├── Class_2/              # Class exercises and examples
│   ├── Class_3/              # Class exercises and examples
│   ├── Class 4/              # Class exercises and examples
│   ├── Class 5/              # Class exercises and examples
│   ├── Class 6/              # Class exercises and examples
│   ├── Homework/             # Homework assignments
│   ├── Practice/             # Practice problems
│   └── random codes/         # Experimental and test codes
└── README.md                 # This file
```

## 🔢 Implemented Methods

### Root Finding Methods
- **Bisection Method** (`bisection.py`) - Finds roots using the intermediate value theorem
- **Newton-Raphson Method** (`newton_raphson.py`) - Fast convergence using derivatives
- **Secant Method** (`secant.py`) - Similar to Newton-Raphson but doesn't require derivatives
- **False Position Method** (`false_position.py`) - Modified bisection with linear interpolation
- **Fixed Point Iteration** (`fixed_point.py`) - Iterative method for fixed point problems

### Linear Equation Solvers
- **Gauss-Jordan Elimination** (`gauss_jordan.hpp`) - Complete elimination method
- **Gauss-Seidel Method** (`gauss_seidal.hpp`) - Iterative solver for large systems
- **Jacobi Iteration** (`jacobi_iteration.cpp`) - Parallel iterative method
- **Cramer's Rule** (`cramers_rule.cpp`) - Determinant-based solver (for small systems)
- **Basic Gaussian Elimination** (`basic_gauss_elimination.hpp`) - Forward elimination with back substitution

### Differential Equation Solvers
- **Euler's Method** (`eulers.py`) - First-order approximation method
- **Heun's Method** (`heun.py`) - Improved Euler's method
- **Runge-Kutta Method** (`runge_kutta.py`) - Fourth-order accurate method

### Numerical Integration
- **Integration Methods** (`integration.py`) - Implements:
  - Trapezoidal Rule
  - Simpson's 1/3 Rule
  - Simpson's 3/8 Rule

### Regression Analysis
- **Least Square Regression** (`least_square_regression.cpp`) - Linear regression
- **Polynomial Regression** (`polynomial.cpp`) - Higher-order polynomial fitting
- **Transcendental Regression** (`transcendental.cpp`) - Non-linear curve fitting

### Utilities
- **Algebraic Expression Evaluator** (`Common/algebraic_expression_evaluator.py`) - Parses and evaluates mathematical expressions
- **Linear Equations Helper** (`Common/linear_equations.hpp`) - Common functions for matrix operations

## 🚀 Getting Started

### Prerequisites

**For C++ files:**
- GCC compiler (g++) version 7.0 or higher
- Standard C++ libraries

**For Python files:**
- Python 3.6 or higher
- Standard Python libraries (math, re)

**For C files:**
- GCC compiler (gcc)
- Standard C libraries

### Compilation Instructions

#### C++ Files
```bash
# Navigate to the All Methods directory
cd "Codes/All Methods"

# Compile a C++ file (example with jacobi_iteration.cpp)
g++ -o jacobi_iteration jacobi_iteration.cpp

# For files that use header files
g++ -o linear_solver linear_equation_solver.cpp
```

#### Python Files
```bash
# Navigate to the All Methods directory
cd "Codes/All Methods"

# Run Python files directly
python3 bisection.py
python3 newton_raphson.py
```

## 📖 Usage Examples

### Root Finding - Bisection Method
```bash
python3 bisection.py
```
**Input:**
```
x^2 - 4
0 3
```
**Output:**
```
Root = 2.000000
```

### Linear Equations - Jacobi Iteration
```bash
g++ -o jacobi jacobi_iteration.cpp
./jacobi
```
**Input:**
```
Enter number of variables: 
3
4x + y + z = 7
x + 3y + z = 8
x + y + 5z = 10
```
**Note:** The linear equation solvers require specific formatting. Ensure proper spacing and use `x`, `y`, `z` as variables.

### Numerical Integration
```bash
python3 integration.py
```
**Input:**
```
x^2 + 1
0.0 2.0
0.5
```
**Output:**
```
I = 4.75000     (Trapezoidal)
I = 4.6667      (Simpson's 1/3)
I = 4.1719      (Simpson's 3/8)
```

### Differential Equations - Runge-Kutta
```bash
python3 runge_kutta.py
```
**Input:**
```
x + y
y(0) = 1
h = 0.1
stop = 1.0
```
**Output:**
```
y(1.1) = 3.9083
```

## 📝 Input Formats

### Expression Format
- Use `x` as the variable
- Supported operations: `+`, `-`, `*`, `/`, `^` (power)
- Functions: `sin`, `cos`, `tan`, `log`, `exp`
- Example: `x^2 + 2*x - 3`

### Linear Equations Format
For systems of linear equations, use the format:
```
ax + by + cz = d
```
Example:
```
2x + 3y - z = 5
x - y + 2z = 3
3x + y + z = 8
```

### Matrix Input
For matrix operations, enter coefficients row by row including the constant terms.

## 🧮 Common Utilities

### Algebraic Expression Evaluator
- Converts infix expressions to postfix notation
- Evaluates mathematical expressions with variables
- Supports derivative calculations
- Handles complex expressions with proper operator precedence

### Linear Equations Helper
- Matrix creation and manipulation
- Array printing and formatting
- Root calculation and validation
- Sorting and pivoting operations

## 🔧 Advanced Features

### Error Handling
- Convergence checking for iterative methods
- Division by zero detection
- Invalid input validation
- Numerical stability checks

### Precision Control
- Configurable tolerance levels (typically 1e-6)
- Double precision arithmetic
- Proper rounding and formatting

### Known Limitations
- Some linear equation solvers may require specific input formatting
- Large condition numbers may cause numerical instability
- Complex expressions should be simplified for better parsing

## 📊 Performance Notes

- **Iterative methods** (Jacobi, Gauss-Seidel) are suitable for large sparse systems
- **Direct methods** (Gauss-Jordan, Cramer's) are better for small dense systems
- **Runge-Kutta** provides better accuracy than Euler's method for differential equations
- **Newton-Raphson** converges faster than bisection but requires differentiable functions

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-method`)
3. Commit your changes (`git commit -am 'Add new numerical method'`)
4. Push to the branch (`git push origin feature/new-method`)
5. Create a Pull Request

### Code Style Guidelines
- Use descriptive variable names
- Add comments for complex algorithms
- Follow existing formatting conventions
- Include example inputs and expected outputs
- Test with various edge cases

## 📋 TODO / Future Enhancements

- [ ] Add more root finding methods (Brent's method, Illinois method)
- [ ] Implement more integration techniques (Gaussian quadrature)
- [ ] Add error analysis and convergence studies
- [ ] Include graphical visualization options
- [ ] Add unit tests for all methods
- [ ] Optimize algorithms for better performance
- [ ] Add support for complex numbers

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 📞 Contact

For questions, suggestions, or contributions, please open an issue in this repository.

---

**Note:** The `Codes/All Methods/` directory contains the most complete and tested implementations. Other directories contain developmental code, class exercises, and experimental implementations.