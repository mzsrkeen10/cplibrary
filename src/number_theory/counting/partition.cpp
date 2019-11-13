/*
    分割数
    時間計算量 O(nm)

    nのm分割の個数を求める

    Usage:
        引数にn, mを与える
        res[m][n] := nのm分割

    Verified:
        AtCoder dwacon2018-prelims-C Kill/Death
*/

#include <vector>

using i64 = int64_t;

std::vector<std::vector<i64>> set_part(int n, int m) {
    std::vector<std::vector<i64>> res(m + 1, std::vector<i64>(n + 1, 0));
    res[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j - i >= 0) {
                res[i][j] = (res[i - 1][j] + res[i][j - i]) % MOD;
            } else {
                res[i][j] = res[i - 1][j];
            }
        }
    }
    return res;
}
