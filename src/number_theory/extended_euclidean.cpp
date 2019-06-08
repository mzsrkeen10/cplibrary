/*
    ax + by = 1(拡張ユークリッドの互除法)
    時間計算量 O(log max(a,b))

    ax + by = 1を満たす整数x,yを求める

    Usage:
        解はx, yに入る

    Verified:
        AOJ NTL_1_E Extended Euclid Algorithm
*/

using i64 = int64_t;

i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}
