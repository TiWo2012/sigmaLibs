#pragma once

#include <array>
#include <iostream>

#include "sigmaDefines.hpp"

namespace sigma {

template <typename T, std::size_t N>
inline void printArray(const std::array<T, N> &arr) {
  for (std::size_t i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << "\n";
  }
}

template <typename T, std::size_t N>
inline void printMatrix(const Matrix<T, N> &matrix) {
  for (std::size_t i = 0; i < matrix.size(); i++) {
    for (std::size_t j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

template <typename T, std::size_t N>
inline void printCuboid(const sigma::Cuboid<T, N> &cuboid) {
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
