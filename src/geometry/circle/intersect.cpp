/*
    円の交差判定
    時間計算量 O(1)

    Usage:
        二つの円の座標・半径を引数に与える

    Verified:
        AOJ0023 Circles Intersection

    *** 要改善 ***
    誤差を考慮していない
*/

int intersect_circle(double xa, double ya, double ra, double xb, double yb,
                     double rb) {
    double dsq = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    double rs = (ra + rb) * (ra + rb);
    double rd = (ra - rb) * (ra - rb);
    if (dsq > rs) // 衝突していない
        return 0;
    else if (dsq <= rs && dsq >= rd) // 交点をもつ
        return 1;
    else if (ra > rb) // Aの内側にB
        return 2;
    else // Bの内側にA
        return -2;
}
