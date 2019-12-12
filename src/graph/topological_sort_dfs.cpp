/*
    トポロジカルソート (DFS)
    時間計算量 O(|V|+|E|)

    MAX_V : 頂点数の最大値

    Usage:
        graphにグラフを入れ，tsort()を呼び出す．
        sizeはグラフの頂点数．
        戻り値はトポロジカルソート後の頂点の番号

    Verified:
        AtCoder EDPC-G Longest Path
*/

#include <algorithm>
#include <vector>

constexpr int MAX_V = 100005;

bool used[MAX_V] = {0};
std::vector<int> graph[MAX_V];

void dfs(std::vector<int> &v, int n) {
    if (used[n])
        return;
    used[n] = true;
    for (auto e : graph[n])
        dfs(v, e);
    v.push_back(n);
}

std::vector<int> tsort(int size) {
    std::vector<int> res;
    for (int i = 1; i <= size; ++i)
        dfs(res, i);
    std::reverse(res.begin(), res.end());
    return res;
}
