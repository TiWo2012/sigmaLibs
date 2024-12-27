#pragma once

#include <array>
#include <iostream>
#include <vector>

#include "sigmaDefines.hpp"

namespace sigma {
template <typename T, std::size_t N>
inline std::array<T, N> arrayCopy(std::array<T, N> vec) {
  // allocate a temporary array
  std::array<T, N> temp;

  for (std::size_t i = 0; i < vec.size(); i++) {
    temp[i] = vec[i];
  }

  return temp;
}

template <typename T> inline std::vector<T> vectorCopy(std::vector<T> vec) {
  // allocate a temporary array
  std::vector<T> temp;

  for (std::size_t i = 0; i < vec.size(); i++) {
    temp.push_back(vec[i]);
  }

  return temp;
}

// function to strip a defined string from a different string from left to right
inline std::string stripLeft(const std::string &str,
                             const std::string &toStrip) {
  std::string result = str;
  std::size_t pos = result.find(toStrip);
  if (pos != std::string::npos) {
    result.erase(0, pos + toStrip.length());
  }
  return result;
}

inline std::string stripRight(const std::string &str,
                              const std::string &toStrip) {
  std::string result = str;
  std::size_t pos = result.find(toStrip);
  if (pos != std::string::npos) {
    result.erase(pos, toStrip.length());
  }
  return result;
}

inline void Error(const std::string &msg) {
  std::cout << "ERROR: " << msg << "\n";
}

template <typename T, std::size_t N>
inline void printArray(const std::array<T, N> &arr) {
  for (std::size_t i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << "\n";
  }
}

template <typename T> inline void printMatrix(const Matrix<T> &matrix) {
  for (std::size_t i = 0; i < matrix.size(); i++) {
    for (std::size_t j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

template <typename T> inline void printCuboid(const sigma::Cuboid<T> &cuboid) {
  for (std::size_t i = 0; i < cuboid.size(); i++) {
    for (std::size_t j = 0; j < cuboid[i].size(); j++) {
      for (std::size_t k = 0; k < cuboid[i][j].size(); k++) {
        std::cout << cuboid[i][j][k] << " ";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
}
} // namespace sigma
