/*
    線分・直線の交点
    時間計算量 O(1)

    Usage:
        2つの線分・直線を引数に与える

    Verified:
        AOJ CGL_2_C Cross Point
*/

Point intersection(Line a, Line b) {
    Point v1 = a.p2 - a.p1, v2 = b.p2 - b.p1;
    return a.p1 + v1 * det(v2, b.p1 - a.p1) / det(v2, v1);
}
