#pragma once

#include <cmath>
#include <stdexcept>

namespace sigma {
// Check if a number is even
inline bool isEven(int n) { return n % 2 == 0; }

inline bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 4) == 0)
      return false;
  return true;
}

// Template math functions
template <typename T>
  requires std::is_arithmetic_v<T>
inline T max(T a, T b) {
  return a > b ? a : b;
}

template <typename T>
  requires std::is_floating_point_v<T>
inline T ceil(T a) {
  return std::ceil(a);
}

template <typename T>
  requires std::is_floating_point_v<T>
inline T floor(T a) {
  return std::floor(a);
}

inline float Area(float a, float b) { return a * b; }

inline float Volume(float a, float b, float c) { return a * b * c; }

template <typename T>
  requires std::is_floating_point_v<T>
inline T round(T a) {
  return std::round(a);
}

template <typename T>
  requires std::is_arithmetic_v<T>
inline T gcd(T a, T b) {
  while (b != 0) {
    T temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

template <typename T>
  requires std::is_arithmetic_v<T>
inline T lcm(T a, T b) {
  return a * b / gcd(a, b);
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
  requires std::is_integral_v<T> // Only for integral types
inline T sqrt(T a) {
  if (a == 0 || a == 1)
    return a; // Handle base cases

  T left = 0, right = a, result = 0;
  while (left <= right) {
    T mid = left + (right - left) / 2;
    T mid_squared = mid * mid;

    if (mid_squared == a) {
      return mid; // Exact square root
    }
    if (mid_squared < a) {
      left = mid + 1;
      result = mid; // Possible answer, but continue searching for higher values
    } else {
      right = mid - 1;
    }
  }
  return result; // Return the largest integer such that result^2 <= a
}

template <typename T>
  requires std::is_arithmetic_v<T>
inline T cube(T a) {
  return a * a * a;
}

template <typename T>
  requires std::is_integral_v<T> // Only for integral types
inline T cbrt(T a) {
  if (a == 0)
    return 0; // Handle base case

  T left = 0, right = a, result = 0;
  while (left <= right) {
    T mid = left + (right - left) / 2;
    T mid_cubed = mid * mid * mid;

    if (mid_cubed == a) {
      return mid; // Exact cube root
    }
    if (mid_cubed < a) {
      left = mid + 1;
      result = mid; // Possible answer, but continue searching for higher values
    } else {
      right = mid - 1;
    }
  }
  return result; // Return the largest integer such that result^3 <= a
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
