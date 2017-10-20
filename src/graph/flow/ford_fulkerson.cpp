/*
    最大流/最小カット(Ford-Fulkerson法)
    時間計算量 O(F|E|)

    MAX_V : 頂点数の最大値

    Usage:
        add_edge()関数でグラフを構成し,
        max_flow()関数を呼び出す.
        sはソース,tはシンク
*/

#include <cstring>
#include <vector>

#define MAX_V 10000
#define INF 1e9

// 辺を表す構造体 (行き先, 容量, 逆辺)
struct edge {
    int to, cap, rev;
}

std::vector<edge>
    G[MAX_V];     // グラフの隣接リスト表現
bool used[MAX_V]; // DFSですでに調べたかのフラグ

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
    if (v == t)
        return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流を求める
int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0)
            return flow;
        flow += f;
    }
}
