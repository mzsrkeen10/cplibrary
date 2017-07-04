/*
    乗法の逆元を求める(拡張ユークリッド互除法)
    時間計算量 O(log max(a,b))

    Usage:
        gcd(a, md) == 1のときのみ乗法逆元が存在
*/

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
