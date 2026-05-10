#pragma once

#include <array>
#include <utility>

template <typename T>
std::array<T, 3> ex_gcd(T a, T b) {

    T x = 1;
    T y = 0;
    T nx = 0;
    T ny = 1;

    while (b) {
        const T q = a / b;
        nx = std::exchange(x, nx) - q * nx;
        ny = std::exchange(y, ny) - q * ny;
        b = std::exchange(a, b) - q * b;
    }

    return {a, x, y};

}
