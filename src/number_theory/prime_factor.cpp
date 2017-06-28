/*
    素因数分解
    時間計算量 O(√n)

    Usage:
        入力nは正
*/

#include <map>

str::map<int, int> prime_factor(int n) {
  std::map<int, int> res;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1)
    res[n] = 1;
  return res;
}
