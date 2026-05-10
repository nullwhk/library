#pragma once

#include <cstdint>
#include <vector>

template <typename It>
std::vector<std::int32_t> pfx_fn(It it_1, It it_2) {

    const std::int32_t n = it_2 - it_1;

    std::vector<std::int32_t> pi(n);

    for (std::int32_t i = 1; i < n; ++i) {
        auto& j = pi[i];
        j = pi[i - 1];
        while (j && it_1[i] != it_1[j]) {
            j = pi[j - 1];
        }
        j += it_1[i] == it_1[j];
    }

    return pi;

}
