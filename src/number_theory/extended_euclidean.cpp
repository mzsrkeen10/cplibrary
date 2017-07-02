/*
    ax + by = 1(拡張ユークリッドの互除法)
    時間計算量 O(log max(a,b))

    ax + by = 1を満たす整数x,yを求める
*/

long long int extgcd(long long int a, long long int b, long long int &x, long long int &y) {
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
