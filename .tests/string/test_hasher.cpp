#include <string>

#include "external/doctest.h"

#include "string/hasher.cpp"

TEST_CASE("hasher") {

    using hshr = hasher<998244353>;

    const std::string str("abaaba");

    hshr hs(std::begin(str), std::end(str));

    CHECK(hs.qry(0, 3) == hs.qry(3, 6));
    CHECK(hs.qry(0, 3) != hs.qry(2, 4));
    CHECK(hs.qry(1, 5) != hs.qry(2, 4));

    hs.push('a');
    hs.push('b');

    CHECK(hs.qry(0, 4) == hs.qry(3, 7));
    CHECK(hs.qry(1, 4) == hs.qry(4, 7));
    CHECK(hs.qry(1, 5) == hs.qry(4, 8));
    CHECK(hs.qry(0, 8) == hs.qry(0, 8));
    CHECK(hs.qry(0, 6) != hs.qry(2, 8));
    CHECK(hs.qry(0, 7) != hs.qry(1, 8));
    CHECK(hshr::hash(std::begin(str), std::end(str)) == hs.qry(0, 6));
    CHECK(hshr::hash(std::begin(str), std::begin(str) + 2) == hs.qry(6, 8));
    CHECK(hshr::hash(std::begin(str) + 1, std::begin(str) + 5) == hs.qry(4, 8));

}
