/*
    約数の列挙
    時間計算量 O(√n)

    Usage:
        入力nは正
*/

#include <vector>

std::vector<int> divisor(int n) {
  std::vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i)
        res.push_back(n / i);
    }
  }
  return res;
}
