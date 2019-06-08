/*
    累乗を求める(繰り返し二乗法)
    時間計算量 O(log n)

    Usage:
        引数にx,nを与えるとx^n % MODを返す

    Verified:
        AOJ NTL_1_B Power
*/

using i64 = int64_t;

constexpr i64 MOD = 1000000007;

i64 repeated_squaring(i64 x, i64 n) {
    i64 res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
