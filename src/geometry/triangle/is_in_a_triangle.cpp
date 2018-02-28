/*
    三角形の内外判定
    時間計算量 O(1)

    Usage:
        引数に三角形の頂点と判定したい点を与える
        点及び辺上は外部として判定される

    Verified:
        AOJ0012 A Point in a Triangle
*/

bool is_in_a_triangle(Point a, Point b, Point c, Point p) {
    double c1 = det(b - a, p - a);
    double c2 = det(c - b, p - b);
    double c3 = det(a - c, p - c);
    if (sgn(c1) == sgn(c2) && sgn(c2) == sgn(c3) && sgn(c1) != 0)
        return true;
    else
        return false;
}
