/*
    多角形-点の包含判定
    時間計算量 O(n)

    点が多角形の内部に存在するか判定する

    Usage:
        多角形と点を引数に与える
        戻り値はそれぞれ,
            - OUT: 外部
            - ON: 辺上
            - IN: 内部
        template.cppが必要

    Verified:
        AOJ CGL_3_C Polygon-Point Containment
*/

enum { OUT, ON, IN };

int contains(const Polygon &poly, const Point &p) {
    bool in = false;
    for (int i = 0; i < poly.size(); i++) {
        Point a = curr(poly, i) - p, b = next(poly, i) - p;
        if (sgn(a.imag() - b.imag()) == 1)
            swap(a, b);
        if (sgn(a.imag()) <= 0 && sgn(b.imag()) > 0)
            if (sgn(det(a, b)) > 0)
                in = !in;
        if (sgn(det(a, b)) == 0 && sgn(dot(a, b)) <= 0)
            return ON;
    }
    return in ? IN : OUT;
}
