/*
    最小全域木(kruskal法)
    時間計算量 O(|E|log|V|)

    Usage:
        ***UnionFindTreeクラスが必要***
        引数に頂点数,辺の列を与える

        非連結なグラフに適用した場合,
        「各連結成分における最小全域木」の集合を求められる

    Verified:
        AOJ GRL_2_A Minimum Spanning Tree
*/

#include <algorithm>

// u,v : 始点と終点
struct Edge {
    int u, v, cost;
};

int kruskal(int v, std::vector<Edge> &es) {
    std::sort(es.begin(), es.end(), [](const Edge &e1, const Edge &e2) {
        return e1.cost < e2.cost;
    }); // Edge.costが小さい順にソートする
    UnionFindTree uft = UnionFindTree(v); // Union-Findの初期化
    int res = 0;
    for (auto e : es) {
        if (!uft.same(e.u, e.v)) {
            uft.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}
