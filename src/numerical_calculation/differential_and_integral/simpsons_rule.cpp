/*
    数値積分(シンプソンの公式)
    計算量 O(n)

    Usage:
      a : 下端
      b : 上端
      n : 分割数
*/

double simpsons_rule(double a, double b, int n) {
  double acc1 = 0, d = (b - a) * 2.0 / n, acc2 = func(a + d);
  for (int i = 2; i < 2 * n - 1; i += 2) {
    acc1 += func(a + i * d);
    acc2 += func(a + (i + 1) * d);
  }
  return (func(a) + 4 * acc1 + 2 * acc2 + func(b)) * h / 3.0;
}
