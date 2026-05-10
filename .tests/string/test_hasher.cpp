#include <string>

#include "external/doctest.h"

#include "string/hasher.cpp"

TEST_CASE("hasher") {

    using hshr = hasher<998244353>;

    const std::string str("abaaba");

    hshr hsh(std::begin(str), std::end(str));

    CHECK(hsh.qry(0, 3) == hsh.qry(3, 6));
    CHECK(hsh.qry(0, 3) != hsh.qry(2, 4));
    CHECK(hsh.qry(1, 5) != hsh.qry(2, 4));

    hsh.push('a');
    hsh.push('b');

    CHECK(hsh.qry(0, 4) == hsh.qry(3, 7));
    CHECK(hsh.qry(1, 4) == hsh.qry(4, 7));
    CHECK(hsh.qry(1, 5) == hsh.qry(4, 8));
    CHECK(hsh.qry(0, 8) == hsh.qry(0, 8));
    CHECK(hsh.qry(0, 6) != hsh.qry(2, 8));
    CHECK(hsh.qry(0, 7) != hsh.qry(1, 8));
    CHECK(hshr::hash(std::begin(str), std::end(str)) == hsh.qry(0, 6));
    CHECK(hshr::hash(std::begin(str), std::begin(str) + 2) == hsh.qry(6, 8));
    CHECK(hshr::hash(std::begin(str) + 1, std::begin(str) + 5) == hsh.qry(4, 8));

}
