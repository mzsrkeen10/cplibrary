/*
    強連結成分分解
    時間計算量 O(|V|+|E|)

    Usage:
        graph: 有向グラフ
        decompose()で強連結成分分解を行う
        operator[]は頂点vが属する強連結成分を返す

    Verified:
        AOJ GRL_3_C Strongly Connected Components
*/

#include <deque>
#include <vector>

using Graph = std::vector<std::vector<int>>;

class StronglyConnectedComponents {
  private:
    const Graph &graph;
    Graph g, rg;
    std::deque<int> order;
    std::deque<bool> used;
    std::vector<int> num_components;

    void dfs(int v) {
        used[v] = true;
        for (auto to : g[v]) {
            if (!used[to])
                dfs(to);
        }
        order.push_front(v);
    }

    void rdfs(int v, int k) {
        num_components[v] = k;
        for (auto to : rg[v]) {
            if (num_components[to] == -1)
                rdfs(to, k);
        }
    }

  public:
    StronglyConnectedComponents(Graph &graph)
        : graph(graph), g(graph.size()), rg(graph.size()), used(graph.size()),
          num_components(graph.size(), -1) {
        for (int i = 0; i < graph.size(); i++) {
            for (auto e : graph[i]) {
                g[i].push_back((int)e);
                rg[(int)e].push_back(i);
            }
        }
    }

    int operator[](int v) { return num_components[v]; }

    int decompose() {
        for (int v = 0; v < (int)g.size(); v++) {
            if (used[v])
                continue;
            dfs(v);
        }

        int k = 0;
        for (int v : order) {
            if (num_components[v] != -1)
                continue;
            rdfs(v, k);
            k++;
        }

        return k;
    }
};
