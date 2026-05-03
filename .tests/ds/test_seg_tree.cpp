#include <cstdint>
#include <vector>

#include "external/doctest.h"

#include "ds/seg_tree.cpp"

TEST_CASE("seg_tree") {

    using vec = std::vector<std::int32_t>;

    CHECK(seg_tree::log_2(3) == 1);
    CHECK(seg_tree::log_2(5) == 2);
    CHECK(seg_tree::log_2(64) == 6);

    const auto get_1 = [](std::int32_t nd, std::int32_t dir) -> vec {
        vec nds;
        seg_tree::for_pars(
            nd, dir, [&](std::int32_t nd) -> void {
                nds.push_back(nd);
            }
        );
        return nds;
    };
    const auto get_2 = [](std::int32_t nd_1, std::int32_t nd_2) -> vec {
        vec nds;
        seg_tree::for_rng(
            nd_1, nd_2, [&](std::int32_t nd) -> void {
                nds.push_back(nd);
            }
        );
        return nds;
    };
    const auto get_3 = [](std::int32_t nd_1, std::int32_t nd_2) -> vec {
        vec nds;
        seg_tree::for_ord(
            nd_1, nd_2, [&](std::int32_t nd) -> void {
                nds.push_back(nd);
            }
        );
        return nds;
    };

    CHECK(get_1(4, 0) == vec({1, 2}));
    CHECK(get_1(9, 0) == vec({1, 2, 4}));
    CHECK(get_1(13, 0) == vec({1, 3, 6}));
    CHECK(get_1(4, 1) == vec({2, 1}));
    CHECK(get_1(9, 1) == vec({4, 2, 1}));
    CHECK(get_1(13, 1) == vec({6, 3, 1}));
    CHECK(get_2(4, 7) == vec({6, 2}));
    CHECK(get_2(9, 13) == vec({9, 12, 5}));
    CHECK(get_2(8, 16) == vec({1}));
    CHECK(get_3(4, 7) == vec({2, 6}));
    CHECK(get_3(9, 13) == vec({9, 5, 12}));
    CHECK(get_3(8, 16) == vec({1}));

}
