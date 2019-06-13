/*
    凸多角形の切断
    時間計算量 O(n)

    凸多角形を直線で切断し,直線の進行方向左側の凸多角形を返す

    Usage:
        凸多角形と直線を引数に与える
        template.cpp, ccw.cpp, line/intersection.cppが必要

    Verified:
        AOJ CGL_4_C Convex Cut
*/

Polygon convex_cut(const Polygon &pg, const Line &line) {
    const int n = pg.size();
    Polygon res;
    for (int i = 0; i < n; i++) {
        Point p = curr(pg, i), q = next(pg, i);
        if (ccw(line.p1, line.p2, p) != CLOCKWISE)
            res.push_back(p);
        int is = ccw(line.p1, line.p2, p) * ccw(line.p1, line.p2, q);
        if (is < 0 && is > ONLINE_BACK * ONLINE_FRONT)
            res.push_back(intersection(Line(p, q), line));
    }
    return res;
}
