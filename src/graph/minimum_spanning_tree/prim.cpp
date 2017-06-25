/*
    最小全域木(prim法)
    時間計算量 O(|E|log|V|)

    MAX_V : 頂点数の最大値

    Usage:
        cost[MAX_V][MAX_V]に各辺のコストを格納
        Vに頂点数を格納
        used[MAX_V]は初期化不要
*/

#include <algorithm>
#include <queue>

#define MAX_V 10000
#define INF 1e9

typedef pair<int, int> pii; // <cost, to>

int cost[MAX_V][MAX_V]; // cost[u][v]は辺e=(u,v)のコスト(存在しない場合はINF)
bool used[MAX_V]; // 頂点iがXに含まれているか
int V;

int prim() {
  for (int i = 0; i < V; ++i) {
    used[i] = false;
  }
  std::priority_queue<pii, vector<pii>, greater<pii> > que;
  que.push(pii(0, 0));
  int res = 0;

  while (!que.empty()) {
    int cst = que.top().first, v = que.top().second;
    que.pop();
    if (used[v])
      continue;
    used[v] = true;
    res += cst;
    for (int u = 0; u < V; u++)
      que.push(pii(cost[v][u], u));
  }

  return res;
}
