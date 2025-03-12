# Push Swap Project

## Introduction
Push Swap is a project from 42 school that involves sorting a stack of numbers using two stacks (`a` and `b`) and a limited set of operations. The goal is to implement an efficient sorting algorithm that minimizes the number of operations.

## Features
- Uses stack-based sorting algorithm
- Optimized for minimal operations
- Handles small and large sets of numbers
- Error handling for invalid inputs

## Operations
- `sa` - Swap the first two elements of stack `a`
- `sb` - Swap the first two elements of stack `b`
- `ss` - Swap the first two elements of both stacks
- `pa` - Push the top element from `b` to `a`
- `pb` - Push the top element from `a` to `b`
- `ra` - Rotate stack `a` upwards
- `rb` - Rotate stack `b` upwards
- `rr` - Rotate both stacks upwards
- `rra` - Reverse rotate stack `a`
- `rrb` - Reverse rotate stack `b`
- `rrr` - Reverse rotate both stacks

## Installation
### Prerequisites
- A Unix-based system (Linux/macOS recommended)
- GCC or Clang compiler
- Make

### Steps to Install
1. Clone the repository:
   ```sh
   git clone https://github.com/elmehdibelfkih/push_swap.git
   cd push_swap
   ```
2. Compile the project:
   ```sh
   make
   ```
3. Run the program:
   ```sh
   ./push_swap "4 67 3 87 23"
   ```

## Testing with Checker
The project includes a `checker` program to validate sorting correctness:
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Optimization
- Uses different sorting algorithms based on input size:
  - Simple sorting for small inputs (3-5 numbers)
  - Advanced algorithms (QuickSort, Radix Sort, etc.) for larger inputs
- Reduces redundant operations to improve efficiency

## Contributing
Pull requests are welcome. Follow best practices and document any major changes.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Authors
- Your Name (@elmehdibelfkih)

