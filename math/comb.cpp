#pragma once

#include <cstdint>
#include <vector>

template <typename T>
class comb {

private:

    std::vector<T> fact;
    std::vector<T> ifact;
    std::int32_t sz;

public:

    explicit comb() : fact({T(1)}), ifact({T(1)}), sz(1) {}

    explicit comb(std::int32_t cap) : comb() {
        reserve(cap);
    }

    T f(std::int32_t n) {
        reserve(n);
        return fact[n];
    }

    T inv_f(std::int32_t n) {
        reserve(n);
        return ifact[n];
    }

    void reserve(std::int32_t cap) {
        if (cap < sz) {
            return;
        }
        fact.resize(cap + 1);
        ifact.resize(cap + 1);
        for (std::int32_t i = sz; i <= cap; ++i) {
            fact[i] = fact[i - 1] * T(i);
        }
        ifact[cap] = fact[cap].inv();
        for (std::int32_t i = cap - 1; i >= sz; --i) {
            ifact[i] = ifact[i + 1] * T(i + 1);
        }
        sz = cap + 1;
    }

};
