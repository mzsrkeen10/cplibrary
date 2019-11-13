/*
    最小全域有向木(Chu-Liu/Edmonds法)
    時間計算量 O(|E||V|) ! mapを使っているためO(|E||V|log|E|)?

    Usage:
        引数に有向グラフ,根を与える

    Verified:
        AOJ GRL_2_B Minimum-Cost Arborescence
*/

#include <map>
#include <numeric>
#include <tuple>
#include <vector>

using Weight = int;

struct Edge {
    int from, to;
    Weight weight;
};

using Graph = std::vector<std::vector<Edge>>;

constexpr Weight INF = 1e9;

Graph chu_liu_edmonds(const Graph &graph, const int root) {
    const int n = graph.size();

    // 頂点vに入る重み最小の辺でグラフを構築
    std::vector<Weight> min_weight(n, INF), prev(n, -1);
    for (int v = 0; v < n; v++) {
        for (auto &e : graph[v]) {
            if (e.weight < min_weight[e.to]) {
                min_weight[e.to] = e.weight;
                prev[e.to] = v;
            }
        }
    }

    // 閉路の検出
    int cycle = -1;
    std::vector<int> groups(n), used(n, -1);
    iota(groups.begin(), groups.end(), 0);
    for (int v = 0; v < n; v++) {
        if (used[v] != -1 || prev[v] == -1 || v == root)
            continue;

        int cur = v;
        do {
            used[cur] = v;
            cur = prev[cur];
        } while (cur != root && cur != -1 && used[cur] == -1);

        if (used[cur] != v)
            continue;
        cycle = cur;
        groups[cur] = cur;
        for (int u = prev[cur]; u != cur; u = prev[u])
            groups[u] = cur;
        break;
    }

    Graph res(n);
    if (cycle == -1) { // 閉路なし
        for (int v = 0; v < n; v++) {
            if (prev[v] == -1 || v == root)
                continue;
            res[prev[v]].push_back({prev[v], v, min_weight[v]});
        }
    } else { // 閉路あり
        Graph g(n);
        using E = std::tuple<int, int, Weight>;
        std::map<E, Edge> mp;
        for (int v = 0; v < n; v++) {
            for (auto e : graph[v]) {
                int from = groups[v], to = groups[e.to], w = e.weight;
                if (from == to)
                    continue;
                if (to == cycle)
                    w -= min_weight[e.to];
                g[from].push_back({from, to, w});
                mp[E{from, to, w}] = {v, e.to, e.weight};
            }
        }

        Graph tree = chu_liu_edmonds(g, groups[root]);

        int u;
        for (int v = 0; v < n; v++) {
            for (auto e : tree[v]) {
                Edge origin = mp[E{e.from, e.to, e.weight}];
                if (e.to == cycle)
                    u = origin.to;
                res[origin.from].push_back(origin);
            }
        }

        for (int v = 0; v < n; v++) {
            if (groups[v] != cycle || v == u)
                continue;
            res[v].push_back({prev[v], v, min_weight[v]});
        }
    }

    return res;
}
