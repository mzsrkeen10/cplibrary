/*
    円と円の交点
    時間計算量 O(1)

    Usage:
        2つの円を引数に与える
        template.cpp, circle.cpp, intersect.cppが必要

    Verified:
        AOJ CGL_7_E Cross Points of Circles
        ABC 157 F Yakiniku Optimization Problem
*/

vector<Point> intersection(Circle c1, Circle c2) {
    double d = abs(c1.p - c2.p);
    vector<Point> res;
    if (intersectCC(c1, c2) != 1)
        return res;
    double rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
    double rs = sqrt(c1.r * c1.r - rc * rc);
    Point e = (c2.p - c1.p) / d;
    res.push_back(c1.p + e * Point(rc, rs));
    Point p = c1.p + e * Point(rc, -rs);
    if (res[0] == p)
        return res;
    res.push_back(p);
    if (res[1] < res[0])
        swap(res[1], res[0]);
    return res;
}
