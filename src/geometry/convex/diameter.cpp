/*
    凸多角形の直径(キャリパー法)
    時間計算量 O(n)

    Usage:
        引数に凸多角形を与える（反時計回り）
        template.cppが必要

    Verified:
        AOJ CGL_4_B Diameter of a Convex Polygon
*/

double convex_diameter(const Polygon &pg) {
    const int n = pg.size();
    int ps = 0, qs = 0;
    for (int i = 1; i < n; i++) {
        if (pg[i].imag() > pg[ps].imag())
            ps = i;
        if (pg[i].imag() < pg[qs].imag())
            qs = i;
    }
    double diameter = abs(pg[ps] - pg[qs]);

    int p = ps, q = qs, maxp = ps, maxq = qs;
    do {
        if (sgn(det(next(pg, p) - curr(pg, p), next(pg, q) - curr(pg, q))) >= 0)
            q = (q + 1) % n;
        else
            p = (p + 1) % n;
        double d = abs(pg[p] - pg[q]);
        if (sgn(d - diameter) > 0) {
            diameter = d;
            maxp = p;
            maxq = q;
        }
    } while (p != ps || q != qs);
    return diameter;
}
