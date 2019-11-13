/*
    セグメント木
    時間計算量 更新・取得ともにO(log(n))

    モノイドに対する区間取得・一点更新

    Usage:
        size: セグメント木に乗せる列の大きさ
        query_func: 取得用の関数
        update_func: 更新用の関数
        identity: 取得用の単位元
        v: 列の初期値指定用

    Verified:
        AOJ DSL_2_A Range Minimum Query (RMQ)
        AOJ DSL_2_B Range Sum Query
        ABC 125 C GCD on Blackboard
        NIKKEI 2019 2 qual D Shortest Path on a Line
*/

#include <functional>
#include <vector>

template <typename T, typename E> class SegmentTree {
  private:
    int n;
    std::vector<T> node;
    const std::function<T(T, T)> query_func;
    const std::function<T(T, E)> update_func;
    const T identity;

  public:
    SegmentTree() = default;

    SegmentTree(int size, std::function<T(T, T)> query_func,
                std::function<T(T, E)> update_func, T identity,
                std::vector<T> v = std::vector<T>())
        : query_func(query_func), update_func(update_func), identity(identity) {
        n = 1;
        while (n < size)
            n *= 2;
        node.resize(2 * n - 1, identity);
        if (size == v.size())
            build(size, v);
    }

    void build(int size, std::vector<T> v) {
        for (int i = 0; i < size; ++i)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; --i)
            node[i] = query_func(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, E val) {
        x += n - 1;

        node[x] = update_func(node[x], val);
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = query_func(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;

        if (r <= a || b <= l)
            return identity;

        if (a <= l && r <= b)
            return node[k];

        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return query_func(vl, vr);
    }
};
