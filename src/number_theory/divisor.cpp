/*
    約数の列挙
    時間計算量 O(√n)

    Usage:
        入力nは正
*/

#include <vector>

using i64 = int64_t;

std::vector<i64> divisor(i64 n) {
    std::vector<i64> res;
    for (i64 i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    return res;
}
