#pragma once

#include <chrono>
#include <cstdint>
#include <random>
#include <vector>

#include "math/mod_int.cpp"

template <std::int32_t MOD>
class hasher {

private:

    using mint = mod_int<MOD>;

    static inline std::mt19937 rng = std::mt19937(
        std::chrono::steady_clock::now().time_since_epoch().count()
    );
    static inline std::vector pows = {mint(1)};

    static inline const mint base = mint(std::uniform_int_distribution(256, MOD - 2)(rng));

public:

    template <typename It>
    static std::int32_t hash(It it_1, It it_2) {
        mint hsh;
        while (it_1 != it_2) {
            hsh = hsh * base + mint(*it_1);
            ++it_1;
        }
        return hsh.val;
    }

    std::vector<mint> pfxs;

    explicit hasher() : pfxs(1) {}

    template <typename It>
    explicit hasher(It it_1, It it_2) : hasher() {
        const std::int32_t sz = it_2 - it_1;
        pfxs.reserve(sz + 1);
        pows.reserve(sz + 1);
        while (it_1 != it_2) {
            pfxs.push_back(pfxs.back() * base + mint(*it_1));
            ++it_1;
        }
        while (std::size(pows) < std::size(pfxs)) {
            pows.push_back(pows.back() * base);
        }
    }

    template <typename T>
    void push(T val) {
        pfxs.push_back(pfxs.back() * base + mint(val));
        if (std::size(pows) < std::size(pfxs)) {
            pows.push_back(pows.back() * base);
        }
    }

    std::int32_t qry(std::int32_t idx_1, std::int32_t idx_2) const {
        return (pfxs[idx_2] - pfxs[idx_1] * pows[idx_2 - idx_1]).val;
    }

};
