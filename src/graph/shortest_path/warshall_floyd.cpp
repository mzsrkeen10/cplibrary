/*
    全点対最短経路(Warshall-Floyd法)
    時間計算量 O(|V|^3)

    MAX_V : 頂点数の最大値

    Usage:
        d[MAX_V][MAX_V]にコストの初期値を格納
        Vに頂点数を格納
*/

#define MAX_V 10000
#define INF 1e9

int d[MAX_V][MAX_V]; // d[u][v]は辺e=(u,v)のコスト(存在しない場合はINF、ただしd[i][i]=0とする)
int V;       // 頂点数

void warshall_floyd() {
  for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
