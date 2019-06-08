/*
    乗法の逆元を求める(拡張ユークリッド互除法)
    時間計算量 O(log max(a,b))

    Usage:
        *** extgcdが必要 ***
        gcd(a, md) == 1のときのみ乗法逆元が存在
*/

using i64 = int64_t;

// a : 元, md : 法
i64 multi_inv(i64 a, i64 md) {
    i64 x, y;
    extgcd(md, a, x, y);
    return (y > 0 ? y : md + y);
}
