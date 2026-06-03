#pragma once

#include <algorithm>
#include <bit>
#include <cstdint>
#include <utility>
#include <vector>

template <typename T>
std::vector<T> fft(std::vector<T> vec, std::int32_t inv, const std::vector<T>& rts) {

    if (std::empty(vec)) {
        return {};
    }

    const std::int32_t sz = std::size(vec);
    std::int32_t idx = 0;

    for (std::int32_t i = 1; i < sz; ++i) {
        std::int32_t bit = sz >> 1;
        while (idx & bit) {
            idx ^= bit;
            bit >>= 1;
        }
        idx |= bit;
        if (i < idx) {
            std::swap(vec[i], vec[idx]);
        }
    }

    for (std::int32_t i = 2; i <= sz; i *= 2) {
        for (std::int32_t j = 0; j < sz; j += i) {
            T rt(1);
            for (std::int32_t k = j; k < j + i / 2; ++k) {
                const T val_1 = vec[k];
                const T val_2 = vec[k + i / 2] * rt;
                vec[k] = val_1 + val_2;
                vec[k + i / 2] = val_1 - val_2;
                rt *= rts[std::countr_zero<std::uint32_t>(i)];
            }
        }
    }

    if (inv) {
        std::reverse(std::begin(vec) + 1, std::end(vec));
        const T rcp = T(1) / T(sz);
        for (auto& x : vec) {
            x *= rcp;
        }
    }

    return vec;

}
