/*
    素因数分解
    時間計算量 O(√n)

    Usage:
        入力nは正

    Verified:
        AOJ NTL_1_A Prime Factorize
*/

#include <map>

using i64 = int64_t;

std::map<i64, i64> prime_factor(i64 n) {
    std::map<i64, i64> res;
    for (i64 i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1)
        res[n] = 1;
    return res;
}
