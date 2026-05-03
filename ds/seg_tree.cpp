#pragma once

#include <bit>
#include <cstdint>

namespace seg_tree {

    constexpr std::int32_t log_2(std::int32_t x) {

        return std::bit_width<std::uint32_t>(x) - 1;

    }

    template <typename F>
    void for_pars(std::int32_t nd, std::int32_t dir, F f) {

        const std::int32_t lg = log_2(nd);

        for (std::int32_t i = 1; i <= lg; ++i) {
            f(nd >> (dir == 0 ? lg - i + 1 : i));
        }

    }

    template <typename F>
    void for_rng(std::int32_t nd_1, std::int32_t nd_2, F f) {

        while (nd_1 < nd_2) {
            if (nd_1 & 1) {
                f(nd_1);
                ++nd_1;
            }
            if (nd_2 & 1) {
                --nd_2;
                f(nd_2);
            }
            nd_1 >>= 1;
            nd_2 >>= 1;
        }

    }

    template <typename F>
    void for_ord(std::int32_t nd_1, std::int32_t nd_2, F f) {

        if (nd_2 - nd_1 <= 0) {
            return;
        }

        const std::int32_t msk = (1 << log_2((nd_1 - 1) ^ nd_2)) - 1;

        std::int32_t nd = -nd_1 & msk;

        while (nd) {
            const std::int32_t bit = std::countr_zero<std::uint32_t>(nd);
            f(((nd_1 - 1) >> bit) + 1);
            nd ^= 1 << bit;
        }

        nd = nd_2 & msk;

        while (nd) {
            const std::int32_t bit = log_2(nd);
            f((nd_2 >> bit) - 1);
            nd ^= 1 << bit;
        }

    }

}
