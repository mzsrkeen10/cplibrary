/*
    線分/直線の交差判定
    時間計算量 O(1)

    Usage:
        引数に2つの直線/線分を与える
        線分の場合はsegflagをtrueにする
        template.cpp, ccw.ccpが必要

    Verified:
        AOJ CGL_2_B Intersection (線分のみ)
*/

bool intersectLS(Line a, Line b, bool segflag) {
    if (segflag)
        return (ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2) <= 0) &&
               (ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2) <= 0);
    else
        return (sgn(det(a.p2 - a.p1, b.p1 - a.p1) *
                    det(a.p2 - a.p1, b.p2 - a.p1)) <= 0) &&
               (sgn(det(b.p2 - b.p1, a.p1 - b.p1) *
                    det(b.p2 - b.p1, a.p2 - b.p1)) <= 0);
}
