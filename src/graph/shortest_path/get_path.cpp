/*
    経路復元(dijkstra)
    時間計算量 O(|V|^2)
    要改善
*/

#include <algorithm>
#include <vector>

constexpr int MAX_E = 10000;
constexpr int MAX_V = 10000;
constexpr int INF = 1e9;

int cost[MAX_V][MAX_V]; // cost[u][v]は辺e=(u,v)のコスト(存在しない場合はINF)
int d[MAX_V];     // 頂点sからの最短距離
bool used[MAX_V]; // すでに使われたかのフラグ
int V;            // 頂点数
int prev[MAX_V];  // 最短路の直前の頂点

// 始点sから各頂点への最短距離を求める
void dijkstra(int s) {
    std::fill(d, d + V, INF);
    std::fill(used, used + V, false);
    std::fill(prev, prev + V, -1);
    d[s] = 0;

    while (true) {
        int v = -1;
        for (int u = 0; u < V; u++) {
            if (!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        }

        if (v == -1)
            break;
        used[v] = true;

        for (int u = 0; u < V; u++) {
            if (d[u] > d[v] + cost[v][u]) {
                d[u] = d[v] + cost[v][u];
                prev[u] = v;
            }
        }
    }
}

// 頂点tへの最短路
std::vector<int> get_path(int t) {
    vector<int> path;
    for (; t != -1; t = prev[t])
        path.push_back(t); // tがsになるまでprev[t]を辿っていく
    // このままだとt->sの順になっているので逆順にする
    std::reverse(path.begin(), path.end());
    return path;
}
