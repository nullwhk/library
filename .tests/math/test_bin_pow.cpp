#include "external/doctest.h"

#include "math/bin_pow.cpp"

TEST_CASE("bin_pow") {

    CHECK(bin_pow(5, 4) == 625);
    CHECK(bin_pow(2, 24) == 1 << 24);
    CHECK(bin_pow(-3, 3) == -27);
    CHECK(bin_pow(-1, 56422304) == 1);
    CHECK(bin_pow(12, 0) == 1);
    CHECK(bin_pow(4, -4) == 1);
    CHECK(bin_pow(12, 5, 0) == 0);

}
