/*
    最小全域木(kruskal法)
    時間計算量 O(|E|log|V|)

    MAX_E : 辺数の最大値
    MAX_N : Union-Find木の配列の要素数

    Usage:
        ***UnionFindTreeクラスが必要***
        edge es[MAX_E]に辺を格納
        V,Eに頂点数,辺数を格納

        非連結なグラフに適用した場合,
        「各連結成分における最小全域木」の集合を求められる
*/

#include <algorithm>

#define MAX_E 10000
#define MAX_N 10000
#define INF 1e9

// u,v : 始点と終点
struct edge {
    int u, v, cost;
};

bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

edge es[MAX_E];
int V, E; // 頂点数と辺数

int kruskal() {
    std::sort(es, es + E, comp); // edge.costが小さい順にソートする
    UnionFindTree uft;
    uft.init(V); // Union-Findの初期化
    int res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!uft.same(e.u, e.v)) {
            uft.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}
