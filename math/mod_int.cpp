#pragma once

#include <cstdint>

#include "math/ex_gcd.cpp"

template <std::int32_t MOD>
class mod_int {

public:

    static std::int32_t mod() {
        return MOD;
    }

    std::int32_t val;

    explicit mod_int() : val(0) {}

    explicit mod_int(std::int64_t val) : val(val % mod()) {
        if (this->val < 0) {
            this->val += mod();
        }
    }

    mod_int operator-() const {
        return mod_int(-val);
    }

    void operator++() {
        *this += mod_int(1);
    }

    void operator--() {
        *this -= mod_int(1);
    }

    void operator+=(mod_int other) {
        if (other.val >= mod() - val) {
            val -= mod();
        }
        val += other.val;
    }

    void operator-=(mod_int other) {
        val -= other.val;
        if (val < 0) {
            val += mod();
        }
    }

    void operator*=(mod_int other) {
        val = (std::int64_t(val) * other.val) % mod();
    }

    void operator/=(mod_int other) {
        *this *= other.inv();
    }

    mod_int inv() const {
        return mod_int(ex_gcd(val, mod())[1]);
    }

    friend bool operator==(mod_int lhs, mod_int rhs) {
        return lhs.val == rhs.val;
    }

    friend bool operator!=(mod_int lhs, mod_int rhs) {
        return lhs.val != rhs.val;
    }

    friend mod_int operator+(mod_int lhs, mod_int rhs) {
        lhs += rhs;
        return lhs;
    }

    friend mod_int operator-(mod_int lhs, mod_int rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend mod_int operator*(mod_int lhs, mod_int rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend mod_int operator/(mod_int lhs, mod_int rhs) {
        lhs /= rhs;
        return lhs;
    }

};
