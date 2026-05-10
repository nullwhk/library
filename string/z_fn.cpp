#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>

template <typename It>
std::vector<std::int32_t> z_fn(It it_1, It it_2) {

    const std::int32_t n = it_2 - it_1;
    std::int32_t l = 0;
    std::int32_t r = 0;

    std::vector<std::int32_t> z(n);

    for (std::int32_t i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = std::min(z[i - l], r - i);
        }
        while (z[i] + i < n && it_1[i + z[i]] == it_1[z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    return z;

}
