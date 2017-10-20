/*
    素因数分解
    時間計算量 O(√n)

    Usage:
        入力nは正
*/

#include <map>

std::map<long long int, long long int> prime_factor(long long int n) {
  std::map<long long int, long long int> res;
  for (long long int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1)
    res[n] = 1;
  return res;
}
