/*
    最大公約数/最小公倍数(Euclid's Algorithm)
    時間計算量 O(log n)
*/

long long int gcd(long long int m, long long int n) {
    return (n == 0 ? m : gcd(n, m % n));
}

long long int lcm(long long int m, long long int n) {
    return m / gcd(m, n) * n;
}
