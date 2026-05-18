#include "external/doctest.h"

#include "math/comb.cpp"
#include "math/mod_int.cpp"

TEST_CASE("comb") {

    using mint = mod_int<998244353>;

    comb<mint> cb;

    CHECK(cb.f(0) == mint(1));
    CHECK(cb.f(3) == mint(6));
    CHECK(cb.f(120) == mint(378780110));
    CHECK(cb.inv_f(0) == mint(1));
    CHECK(cb.inv_f(3) == mint(166374059));
    CHECK(cb.inv_f(120) == mint(476753735));

    cb = comb<mint>(22);

    cb.reserve(100);

    CHECK(cb.f(5) == mint(120));
    CHECK(cb.inv_f(5) == mint(856826403));

}
