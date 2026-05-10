#include <cstdint>
#include <string>
#include <vector>

#include "external/doctest.h"

#include "string/z_fn.cpp"

TEST_CASE("z_fn") {

    using vec = std::vector<std::int32_t>;

    std::string s("aaabaab");

    CHECK(z_fn(std::begin(s), std::end(s)) == vec({0, 2, 1, 0, 2, 1, 0}));

    s.assign("abacaba");

    CHECK(z_fn(std::begin(s), std::end(s)) == vec({0, 0, 1, 0, 3, 0, 1}));

}
