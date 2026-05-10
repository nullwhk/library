#include "external/doctest.h"

#include "ds/dsu.cpp"

TEST_CASE("dsu") {

    dsu uf(4);

    CHECK(uf.find(0) == 0);
    CHECK(uf.find(1) == 1);
    CHECK(uf.find(2) == 2);
    CHECK(uf.find(3) == 3);

    uf.unite(2, 3);

    CHECK(uf.find(2) == uf.find(3));
    CHECK(uf.find(0) != uf.find(3));
    CHECK(uf.szs[uf.find(0)] == 1);
    CHECK(uf.szs[uf.find(2)] == 2);

    uf.unite(0, 1);
    uf.unite(1, 3);

    CHECK(uf.find(0) == uf.find(3));
    CHECK(uf.find(1) == uf.find(2));
    CHECK(uf.szs[uf.find(2)] == 4);

    uf = dsu(5);

    uf.unite(2, 3);
    uf.unite(3, 4);

    CHECK(uf.find(0) != uf.find(1));
    CHECK(uf.find(1) != uf.find(2));
    CHECK(uf.find(2) == uf.find(3));
    CHECK(uf.find(3) == uf.find(4));
    CHECK(uf.szs[uf.find(0)] == 1);
    CHECK(uf.szs[uf.find(1)] == 1);
    CHECK(uf.szs[uf.find(2)] == 3);
    CHECK(uf.szs[uf.find(3)] == 3);
    CHECK(uf.szs[uf.find(4)] == 3);

}
