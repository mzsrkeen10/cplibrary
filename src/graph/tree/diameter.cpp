/*
    木の直径
    時間計算量 O(|V|)

    木の直径と両端の点を返す

    Usage:
        引数に木(0-indexed)を与える
        戻り値は両端の点のインデックスと直径
    Verified:
        AOJ 1595 Traffic Tree
*/

#include <queue>
#include <tuple>
#include <utility>
#include <vector>

struct Edge {
    int from, to, cost;
};

using Graph = std::vector<std::vector<Edge>>;
using Weight = int;

constexpr Weight INF = 1e9;

std::tuple<int, int, Weight> tree_diameter(const Graph &tree) {
    struct {
        std::pair<Weight, int> operator()(int v, const Graph &tree) {
            std::pair<Weight, int> res(0, v);
            std::vector<Weight> dist(tree.size(), INF);
            dist[v] = 0;
            std::queue<pair<Weight, int>> que;
            que.push({0, v});
            while (!que.empty()) {
                auto cur = que.front();
                que.pop();
                res = max(res, cur);
                for (auto e : tree[cur.second]) {
                    Weight new_cost = cur.first + e.cost;
                    if (new_cost >= dist[e.to])
                        continue;
                    dist[e.to] = new_cost;
                    que.push({new_cost, e.to});
                }
            }
            return res;
        }
    } find_farthest_node;

    auto r = find_farthest_node(0, tree);
    auto t = find_farthest_node(r.second, tree);
    return make_tuple(r.second, t.second, t.first);
}
