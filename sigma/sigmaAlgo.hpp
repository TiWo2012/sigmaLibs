#pragma once

#include "sigmaDefines.hpp"

#include <cstddef>
#include <string>
#include <type_traits>
#include <vector>

namespace sigma {

template <typename T, std::size_t N>
  requires std::is_arithmetic_v<T>
inline std::vector<T> Bublesort(std::vector<T> arr) {
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
  return arr;
}

inline std::string encrypt(std::string input, sigma::uint8 key) {
  std::string mid = "";
  for (char c : input) {
    mid += c + key;
  }

  std::string output = "";

  for (char c : mid) {
    output += c - key * 255;
  }

  return output;
}

inline std::string decrypt(std::string input, sigma::uint8 key) {
  std::string mid = "";
  for (char c : input) {
    mid += c - key;
  }

  std::string output = "";

  for (char c : mid) {
    output += c + key * 255;
  }

  return output;
}

} // namespace sigma
