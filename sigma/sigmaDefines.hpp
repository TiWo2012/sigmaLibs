#pragma once

#include <array>
#include <cstdint>

namespace sigma {
using i8 = std::int8_t;
using ui8 = std::uint8_t;
using i16 = std::int16_t;
using ui16 = std::uint16_t;
using i32 = std::int32_t;
using ui32 = std::uint32_t;
using i64 = std::int64_t;
using ui64 = std::uint64_t;

template <typename T, std::size_t N>
using Matrix = std::array<std::array<T, N>, N>;

template <typename T, std::size_t N>
using Cuboid = std::array<std::array<std::array<T, N>, N>, N>;


}; // namespace sigma