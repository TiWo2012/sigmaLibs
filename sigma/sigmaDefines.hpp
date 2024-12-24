#pragma once

#include <array>
#include <cstdint>

namespace sigma {
using int8 = std::int8_t;
using uint8 = std::uint8_t;
using int16 = std::int16_t;
using uint16 = std::uint16_t;
using int32 = std::int32_t;
using uint32 = std::uint32_t;
using int64 = std::int64_t;
using uint64 = std::uint64_t;

template <typename T, std::size_t N>
using Matrix = std::array<std::array<T, N>, N>;

template <typename T, std::size_t N>
using Cuboid = std::array<std::array<std::array<T, N>, N>, N>;

}; // namespace sigma
