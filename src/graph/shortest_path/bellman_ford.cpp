/*
    単一始点最短経路(Bellman-Ford法)
    時間計算量 O(|V||E|)

    Usage:
        v : 頂点数
        e : 辺数
        s : 始点
        mini : 最短距離を格納するvector（あらかじめ初期化しておく）
        edges : 辺
        始点から到達可能な負閉路が存在する場合はfalseを，それ以外はtrueを返す

    Verified:
        AOJ GRL_1_B Single Source Shortest Path (Negative Edges)
*/

#include <cstring>

using i64 = int64_t;

constexpr int INF = 1e9;

struct Edge {
    int from, to;
    i64 cost;
};

bool bellman_ford(int v, int e, int s, vector<i64> &mini, const vector<Edge> &edges) {
    for(int i = 0; i < 2*v; i++) {
        bool update = false;
        for (auto e: edges) {
            if (mini[e.from] != INF && mini[e.to] > mini[e.from] + e.cost) {
                mini[e.to] = mini[e.from] + e.cost;
                update = true;
            }
        }
        if (!update)
            break;
        else if(i >= 2*v - 1)
            return false;
    }
    return true;
}
