#pragma once

#include <cstdint>
#include <numeric>
#include <utility>
#include <vector>

class dsu {

public:

    std::vector<std::int32_t> reps;
    std::vector<std::int32_t> szs;

    explicit dsu(std::int32_t sz) : reps(sz), szs(sz, 1) {
        std::iota(std::begin(reps), std::end(reps), 0);
    }

    std::int32_t find(std::int32_t nd) {
        if (reps[nd] != nd) {
            reps[nd] = find(reps[nd]);
        }
        return reps[nd];
    }

    void unite(std::int32_t nd_1, std::int32_t nd_2) {
        nd_1 = find(nd_1);
        nd_2 = find(nd_2);
        if (nd_1 != nd_2) {
            if (szs[nd_1] < szs[nd_2]) {
                std::swap(nd_1, nd_2);
            }
            reps[nd_2] = nd_1;
            szs[nd_1] += szs[nd_2];
        }
    }

};
