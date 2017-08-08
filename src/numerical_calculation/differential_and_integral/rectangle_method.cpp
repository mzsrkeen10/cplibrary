/*
    数値積分(長方形近似)
    計算量 O(n)

    Usage:
      a : 下端
      b : 上端
      n : 分割数
*/

double rectangle_method(double a, double b, int n) {
  double acc = 0, d = (b - a) / n;
  for (int i = 0; i < n; i++) {
    acc += func(a + i * d) * d;
  }
  return acc;
}
