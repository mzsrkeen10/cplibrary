/*
    素数の列挙(エラトステネスの篩)
    時間計算量 O(n log log n)

    MAX_N : 配列の要素数の最大値

    Usage:
        素数の数が返される
        prime[]には素数の列が,
        is_prime[]には各値が素数か否かが記憶される
*/

#define MAX_N 10000

int prime[MAX_N];         // i番目の素数
bool is_prime[MAX_N + 1]; // is_prime[i]がtrueならばiは素数

// n以下の素数の数を返す
int sieve(int n) {
  int p = 0;
  for (int i = 0; i <= n; i++)
    is_prime[i] = true;
  is_prime[0] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime[p++] = i;
      for (int j = 2 * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }
  return p;
}
