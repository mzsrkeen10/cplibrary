/*
    素数判定
    時間計算量 O(√n)

    Usage:
        入力nは正
        n == 1 の場合は例外
*/

bool is_prime(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return n != 1;
}
