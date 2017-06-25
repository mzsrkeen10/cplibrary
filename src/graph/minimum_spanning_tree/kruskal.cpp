/*
    最小全域木(kruskal法)
    時間計算量 O(|E|log|V|)

    MAX_E : 辺数の最大値
    MAX_V : 頂点数の最大値
    MAX_N : Union-Find木の配列の要素数

    Usage:
        edge es[MAX_E]に辺を格納
        V,Eに頂点数,辺数を格納

        非連結なグラフに適用した場合,
        「各連結成分における最小全域木」の集合を求められる
*/

#include <algorithm>

#define MAX_E 10000
#define MAX_V 10000
#define MAX_N 10000
#define INF 1e9

// u,v : 始点と終点
struct edge {
  int u, v, cost;
};

int par[MAX_N];  // 親
int rank[MAX_N]; // 木の深さ

// n要素で初期化
void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

// 木の根を求める
int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

// xとyの属する集合を併合
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;

  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
  }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y) { return find(x) == find(y); }

bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

edge es[MAX_E];
int V, E; // 頂点数と辺数

int kruskal() {
  std::sort(es, es + E, comp); // edge.costが小さい順にソートする
  init(V);                     // Union-Findの初期化
  int res = 0;
  for (int i = 0; i < E; i++) {
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}
