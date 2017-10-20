/*
    数値積分(台形公式)
    計算量 O(n)

    Usage:
      a : 下端
      b : 上端
      n : 分割数
*/

double trapezoidal_rule(double a, double b, int n) {
    double acc = 0, d = (b - a) / n;
    for (int i = 1; i < n; i++) {
        acc += func(a + i * d);
    }
    acc = (func(a) + 2 * acc + func(b)) * h / 2.0;
    return acc;
}
