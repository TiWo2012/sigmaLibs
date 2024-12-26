#pragma once

#include <cstddef>
#include <stdexcept>

namespace sigma {
// Check if a number is even
inline bool isEven(int n) { return n % 2 == 0; }

// Template math functions
template <typename T>
  requires std::is_arithmetic_v<T>
inline T max(T a, T b) {
  return a > b ? a : b;
}

template <typename T>
  requires std::is_arithmetic_v<T>
inline T min(T a, T b) {
  return a < b ? a : b;
}

template <typename T>
  requires std::is_arithmetic_v<T>
inline T abs(T a) {
  return a < 0 ? -a : a;
}

template <typename T>
  requires std::is_arithmetic_v<T>
inline T sqr(T a) {
  return a * a;
}

template <typename T>
  requires std::is_arithmetic_v<T>
inline T cube(T a) {
  return a * a * a;
}

// Factorial with error handling
inline int factorial(int n) {
  if (n < 0) {
    throw std::invalid_argument(
        "Factorial is not defined for negative numbers.");
  }
  if (n == 1 || n == 0) {
    return 1;
  }
  if (n > 12) {
    throw std::overflow_error(
        "Factorial of numbers greater than 20 is not supported.");
  }
  return n * factorial(n - 1);
}

inline int ToBin(int n) {
  int binaryNumber = 0;
  int remainder, i = 1;

  while (n != 0) {
    remainder = n % 2;
    n /= 2;
    binaryNumber += remainder * i;
    i *= 10;
  }

  return binaryNumber;
}

template <typename T>
  requires std::is_arithmetic_v<T>
inline T pow(const T base, T exp) {
  if (exp == 0)
    return static_cast<T>(1); // any number raised to the power of 0 is 1
  T result = base;
  for (T i = 1; i < exp; ++i) {
    result *= base;
  }
  return result;
}

} // namespace sigma
