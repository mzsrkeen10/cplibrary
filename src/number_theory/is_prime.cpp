/*
    素数判定
    時間計算量 O(√n)

    Usage:
        入力nは正
        n == 1 の場合は例外
*/

using i64 = int64_t;

bool is_prime(i64 n) {
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return n != 1;
}
