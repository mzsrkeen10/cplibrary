#include <cstring>

#define MAX_E 10000
#define MAX_V 10000
#define INF 1e9

// 頂点fromから頂点toへのコストcostの辺
struct edge {
  int from, to, cost;
};

edge es[MAX_E]; // 辺

int d[MAX_V]; // 最短距離
int V, E;     // Vは頂点数、Eは辺数

// s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s) {
  for (int i = 0; i < V; i++)
    d[i] = INF;
  d[s] = 0;
  while (true) {
    bool update = false;
    for (int i = 0; i < E; i++) {
      edge e = es[i];
      if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update)
      break;
  }
}

// trueなら負の閉路が存在する
bool find_negative_loop() {
  memset(d, 0, sizeof(d));

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < E; j++) {
      edge e = es[j];
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;

        // n回目にも更新があるなら負の閉路が存在する
        if (i == V - 1)
          return true;
      }
    }
  }
  return false;
}
