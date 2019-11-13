/*
    単一始点最短経路(dijkstra法)
    時間計算量 O(|E|log|V|)

    MAX_V : 頂点数の最大値

    Usage:
        s : 始点
        Vに頂点数を格納
        vector<edge> G[MAX_V]に各頂点からの辺を格納
        最短経路はd[MAX_V]に格納される
*/
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>

constexpr int MAX_V = 10000;
constexpr int INF = 1e9;

struct edge {
    int to, cost;
};
using P = std::pair<int, int>; // firstは最短距離、secondは頂点の番号

int V;
std::vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    std::fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
