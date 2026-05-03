#include <array>
#include <numeric>

#include "external/doctest.h"

#include "math/ex_gcd.cpp"

TEST_CASE("ex_gcd") {

    std::array res = ex_gcd(12, 27);

    CHECK(res[0] == std::gcd(12, 27));
    CHECK(res[1] * 12 + res[2] * 27 == res[0]);

    res = ex_gcd(31, 8);

    CHECK(res[0] == std::gcd(31, 8));
    CHECK(res[1] * 31 + res[2] * 8 == res[0]);

    res = ex_gcd(0, 8);

    CHECK(res[0] == std::gcd(0, 8));
    CHECK(res[1] * 0 + res[2] * 8 == res[0]);

}
