#include <algorithm>
#include <queue>

#define MAX_E 10000
#define MAX_V 10000
#define INF 1e9

struct edge {
  int to, cost;
};
typedef pair<int, int> P; // firstは最短距離、secondは頂点の番号

int V;
std::vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  std::priority_queue<P, vector<P>, greater<P>> que;
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
