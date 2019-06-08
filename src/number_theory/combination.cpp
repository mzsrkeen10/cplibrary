/*
    組み合わせ

    MAX_N : 配列の要素数の最大値
    MOD : 法

    Usage:
        *** extgcd, multi_invが必要 ***
*/

using i64 = int64_t;

constexpr i64 MAX_N = 10000;
constexpr i64 MOD = 1000000007;

i64 ncr[MAX_N];

void set_ncr(i64 n) {
    ncr[0] = 1;
    for (i64 i = 1; i <= n; i++) {
        i64 inv = multi_inv(i, MOD);
        ncr[i] = (n - i + 1) * ncr[i - 1] % MOD;
        ncr[i] = ncr[i] * inv % MOD;
    }
}
