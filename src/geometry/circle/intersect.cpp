/*
    円の交差判定
    時間計算量 O(1)

    Usage:
        二つの円を引数に与える
        template.cppが必要

    Verified:
        AOJ0023 Circles Intersection
*/

int intersectCC(Circle a, Circle b) {
    double dsq = norm(a.p - b.p);
    double rs = (a.r + b.r) * (a.r + b.r);
    double rd = (a.r - b.r) * (a.r - b.r);
    if (sgn(dsq - rs) == 1) // 重なっていない
        return 0;
    else if (sgn(rs - dsq) >= 0 && sgn(dsq - rd) >= 0) // 共有点をもつ
        return 1;
    else if (sgn(a.r - b.r) == 1) // BがAの内部にある
        return 2;
    else // AがBの内部にある
        return -2;
}
