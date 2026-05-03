#include <cstdint>
#include <vector>

#include "external/doctest.h"

#include "ds/fen_tree.cpp"

TEST_CASE("fen_tree") {

    using vec = std::vector<std::int32_t>;

    const auto get_1 = [](std::int32_t nd, std::int32_t sz) -> vec {
        vec nds;
        fen_tree::for_pars(
            nd, sz, [&](std::int32_t nd) -> void {
                nds.push_back(nd);
            }
        );
        return nds;
    };
    const auto get_2 = [](std::int32_t nd) -> vec {
        vec nds;
        fen_tree::for_rng(
            nd, [&](std::int32_t nd) -> void {
                nds.push_back(nd);
            }
        );
        return nds;
    };

    CHECK(get_1(2, 4) == vec({3, 4}));
    CHECK(get_1(6, 7) == vec({7}));
    CHECK(get_1(0, 8) == vec({1, 2, 4, 8}));
    CHECK(get_2(2) == vec({2}));
    CHECK(get_2(5) == vec({5, 4}));
    CHECK(get_2(7) == vec({7, 6, 4}));

}
