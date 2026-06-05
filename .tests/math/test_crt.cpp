#include <array>
#include <cstdint>

#include "external/doctest.h"

#include "math/crt.cpp"

TEST_CASE("crt") {

    using cong = std::array<std::int32_t, 2>;

    cong cg({1, 0});

    cg = crt(cg, {3, 1});

    CHECK(cg == cong({3, 1}));

    cg = crt(cg, {2, 0});

    CHECK(cg == cong({6, 4}));

    cg = crt(cg, {5, 1});

    CHECK(cg == cong({30, 16}));

    cg = crt(cg, {4, 3});

    CHECK(cg == cong({}));
    CHECK(crt(cong({6, 3}), {8, 5}) == cong({24, 21}));
    CHECK(crt(cong({3, 2}), {3, 2}) == cong({3, 2}));
    CHECK(crt(cong({6, 4}), {8, 5}) == cong({}));
    CHECK(crt(cong({6, 4}), {}) == cong({}));

}
