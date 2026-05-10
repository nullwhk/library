#include <cstdint>
#include <string>
#include <vector>

#include "external/doctest.h"

#include "string/pfx_fn.cpp"

TEST_CASE("pfx_fn") {

    using vec = std::vector<std::int32_t>;

    std::string s("abcabcd");

    CHECK(pfx_fn(std::begin(s), std::end(s)) == vec({0, 0, 0, 1, 2, 3, 0}));

    s.assign("aabaaab");

    CHECK(pfx_fn(std::begin(s), std::end(s)) == vec({0, 1, 0, 1, 2, 2, 3}));

}
