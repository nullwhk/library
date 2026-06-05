#pragma once

#include <array>

#include "math/ex_gcd.cpp"

template <typename T>
std::array<T, 2> crt(const std::array<T, 2>& cg_1, const std::array<T, 2>& cg_2) {

    const auto& [m_1, a_1] = cg_1;
    const auto& [m_2, a_2] = cg_2;

    if (m_1 == 0 || m_2 == 0) {
        return {};
    }

    const auto [gcd, x, y] = ex_gcd(m_1, m_2);

    if ((a_1 - a_2) % gcd) {
        return {};
    }

    const T lcm = m_1 / gcd * m_2;

    std::array<T, 2> cg({lcm, (a_1 + (((x * (a_2 - a_1)) / gcd) % (m_2 / gcd)) * m_1) % lcm});

    if (cg[1] < 0) {
        cg[1] += cg[0];
    }

    return cg;

}
