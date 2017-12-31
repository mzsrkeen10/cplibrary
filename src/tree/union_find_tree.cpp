/*
    Union-Find木
    時間計算量 O(α(n))

    集合の併合と所属判定を高速に行うことが可能
*/

class UnionFindTree {
  private:
    std::vector<int> par;   // 親
    std::vector<int> depth; // 木の深さ

  public:
    // n要素で初期化
    UnionFindTree(int n) {
        for (int i = 0; i < n; i++) {
            par.push_back(i);
            depth.push_back(0);
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
};
