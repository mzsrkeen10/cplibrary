/*
    最大公約数/最小公倍数(Euclid's Algorithm)
    時間計算量 O(log n)

    Verified:
        AOJ NTL_1_C Least Common Multiple
*/

using i64 = int64_t;

i64 gcd(i64 m, i64 n) {
    return (n == 0 ? m : gcd(n, m % n));
}

i64 lcm(i64 m, i64 n) {
    return m / gcd(m, n) * n;
}
