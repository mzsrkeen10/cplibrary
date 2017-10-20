/*
    累乗を求める(繰り返し二乗法)
    時間計算量 O(log n)

    Usage:
        引数にx,nを与えるとx^n % MODを返す
*/

#define MOD 1000000007

typedef long long ll;

ll repeated_squaring(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
