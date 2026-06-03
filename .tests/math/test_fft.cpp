#include <cstdint>
#include <vector>

#include "external/doctest.h"

#include "math/fft.cpp"
#include "math/mod_int.cpp"

TEST_CASE("fft") {

    using mint = mod_int<998244353>;

    const std::vector rts({mint(1), mint(998244352), mint(911660635), mint(372528824)});
    std::vector poly({mint(3), mint(7), mint(4), mint(2)});

    poly = fft(poly, 0, rts);

    CHECK(poly == std::vector({mint(16), mint(565325762), mint(998244351), mint(432918589)}));

    poly = fft(poly, 1, rts);

    CHECK(poly == std::vector({mint(3), mint(7), mint(4), mint(2)}));

    poly.assign({mint(4), mint(-2), mint(3), mint(), mint(), mint(), mint(), mint()});

    poly = fft(poly, 0, rts);

    for (std::int32_t i = 0; i < 8; ++i) {
        poly[i] = poly[i] * poly[i];
    }

    poly = fft(poly, 1, rts);

    CHECK(
        poly == std::vector(
            {mint(16), mint(-16), mint(28), mint(-12), mint(9), mint(), mint(), mint()}
        )
    );

    poly.clear();

    CHECK(std::empty(fft(poly, 0, rts)));

}
