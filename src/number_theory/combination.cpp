/*
    組み合わせ

    MAX_N : 配列の要素数の最大値
    MOD : 法
*/

#define MAX_N 10000
#define MOD 1000000007

long long int ncr[MAX_N];

long long int extgcd(long long int a, long long int b, long long int &x,
                     long long int &y) {
  long long int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

// a : 元, md : 法
long long int multi_inv(long long int md, long long int a) {
  long long int x, y;
  extgcd(md, a, x, y);
  return (y > 0 ? y : md + y);
}

void set_ncr(long long int n) {
  ncr[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    long long int inv = multi_inv(i, MOD);
    ncr[i] = (n - i + 1) * ncr[i - 1] % MOD;
    ncr[i] = ncr[i] * inv % MOD;
  }
}
