#include "external/doctest.h"

#include "math/mod_int.cpp"

TEST_CASE("mod_int") {

    using mint = mod_int<53>;

    CHECK(mint::mod() == 53);
    CHECK(mint(2) == mint(108));
    CHECK(mint(-2) == mint(51));
    CHECK(-mint(2) == mint(51));
    CHECK(mint(2) != mint(51));
    CHECK(mint(3) != mint(4));

    mint num_1(51);
    mint num_2;

    ++num_1;
    --num_2;

    CHECK(num_1 == mint(52));
    CHECK(num_2 == mint(52));

    ++num_1;
    --num_2;

    CHECK(num_1 == mint());
    CHECK(num_2 == mint(51));

    num_1 -= mint(45);
    num_2 += mint(12);

    CHECK(num_1 == mint(8));
    CHECK(num_2 == mint(10));

    num_1 *= mint(3);
    num_2 /= mint(2);

    CHECK(num_1 == mint(24));
    CHECK(num_2 == mint(5));
    CHECK(num_1.inv() == mint(42));
    CHECK(num_2.inv() == mint(32));
    CHECK(mint(-2) + mint(3) == mint(1));
    CHECK(mint(-2) - mint(3) == mint(48));
    CHECK(mint(-2) * mint(3) == mint(47));
    CHECK(mint(-2) / mint(3) == mint(17));

}
