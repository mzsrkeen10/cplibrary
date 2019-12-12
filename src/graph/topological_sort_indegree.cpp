/*
    トポロジカルソート (入次数)
    時間計算量 O(|V|+|E|)

    Usage:
        graphにグラフを入れ，topological_sort()を呼び出す．
        戻り値はトポロジカルソート後の頂点の番号
        res.size()が頂点数に達しなければ，閉路が存在する．

    Verified:
        ABC 139 E League
*/

#include <stack>
#include <vector>

using Graph = vector<vector<int>>;

std::vector<int> topological_sort(const Graph &graph) {
    std::vector<int> indegree(graph.size());
    for (auto edges : graph) {
        for (auto to : edges) {
            indegree[to]++;
        }
    }

    std::stack<int> st;
    for (int i = 0; i < graph.size(); i++) {
        if (indegree[i] == 0)
            st.push(i);
    }

    std::vector<int> res;
    while (!st.empty()) {
        int idx = st.top();
        st.pop();
        res.push_back(idx);
        for (auto to : graph[idx]) {
            indegree[to]--;
            if (indegree[to] == 0) {
                st.push(to);
            }
        }
    }

    return res;
}
