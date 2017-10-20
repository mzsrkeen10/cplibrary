/*
    Union-Find木
    時間計算量 O(α(n))

    MAX_N : 配列の要素数の最大値

    集合の併合と所属判定を高速に行うことが可能
*/

#define MAX_N 10000

int par[MAX_N];   // 親
int depth[MAX_N]; // 木の深さ

// n要素で初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        depth[i] = 0;
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

    if (depth[x] < depth[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (depth[x] == depth[y])
            depth[x]++;
    }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y) { return find(x) == find(y); }
