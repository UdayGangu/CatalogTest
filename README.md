# Shamir's Secret Sharing Algorithm - Simplified Version

## Problem Statement
This project implements a simplified version of **Shamir's Secret Sharing algorithm**. 
Given a polynomial with unknown coefficients, the goal is to determine its constant term by interpolating between given points. 
These points (roots) are encoded in various numerical bases, and the algorithm decodes them and uses interpolation to calculate the constant term `c`.

In this project:
1. We decode Y values (encoded in various bases) from JSON input.
2. We then use **Lagrange interpolation** to calculate the constant term `c` of the polynomial.

## Input Format
The input is in JSON format and contains:
- **n**: Number of roots provided.
- **k**: Minimum number of roots required to solve the polynomial (where `k = m + 1`, with `m` being the polynomial's degree).
- **Roots**: Given as `base` and `value` pairs. Each root has:
  - `x`: Position/index.
  - `base`: The numerical base in which the `y` value is encoded.
  - `value`: The encoded `y` value.

### Example Input
```json
{
  "keys": {
    "n": 4,
    "k": 3
  },
  "1": {
    "base": "10",
    "value": "4"
  },
  "2": {
    "base": "2",
    "value": "111"
  },
  "3": {
    "base": "10",
    "value": "12"
  },
  "6": {
    "base": "4",
    "value": "213"
  }
}
