#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>

template <typename It>
std::vector<std::int32_t> manacher(It it_1, It it_2) {

    const std::int32_t n = it_2 - it_1;
    std::int32_t l = 0;
    std::int32_t r = 0;

    std::vector<std::int32_t> d(n);

    for (std::int32_t i = 0; i < n; ++i) {
        if (i < r) {
            d[i] = std::min(d[l + r - i], r - i);
        }
        while (i - d[i] >= 0 && i + d[i] < n && it_1[i - d[i]] == it_1[i + d[i]]) {
            ++d[i];
        }
        if (i + d[i] > r) {
            l = i - d[i];
            r = i + d[i];
        }
    }

    return d;

}
