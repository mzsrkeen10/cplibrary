/*
    中国剰余定理
    時間計算量 O(k log mi) (?)

    与えられた k 個の整数 m1, m2, ..., mk がどの二つも互いに素のとき，
    任意の整数 a1, a2, ..., ak に対し

        x % m1 = a1,
        x % m2 = a2,
        　　...
        x % mk = ak

    を満たす整数 x が m1m2...mk を法として一意に存在する．

    Usage:
        *** extgcdが必要 ***
*/

#include <vector>

using i64 = int64_t;

i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

pair<i64, i64> chinese_remainder_theorem(const vector<i64> &a,
                                         const vector<i64> &m) {
    i64 x = 0, md = 1;
    for (int i = 0; i < (int)a.size(); ++i) {
        i64 p, q;
        i64 d = extgcd(md, m[i], p, q);
        if ((a[i] - x) % d != 0)
            return make_pair(0, -1);
        i64 tmp = (a[i] - x) / d * p % (m[i] / d);
        x += md * tmp;
        md *= m[i] / d;
    }
    return make_pair(mod(x, md), md);
}
