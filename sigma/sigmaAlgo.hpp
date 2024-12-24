#pragma once

#include <cstddef>
#include <vector>
#include <type_traits>

namespace sigma {

template<typename T, std::size_t N>
requires std::is_arithmetic_v<T>
inline std::vector<T> Bublesort(std::vector<T> arr)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N - i - 1; j++)
        {
        if (arr[j] > arr[j + 1])
        {
            std::swap(arr[j], arr[j + 1]);
        }
        }
    }
    return arr;
}


  
} // namespace sigma