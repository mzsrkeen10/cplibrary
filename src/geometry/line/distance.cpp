/*
    点・線間の距離
    時間計算量 O(1)

    Usage:
        点・線などを引数に与える
        template.cppが必要
        distanceSSはccw.cpp, intersectLS.cppも必要

    Verified:
        AOJ CGL_2_D Distance
*/

double distanceLP(Line line, Point p) {
    return abs(det(line.p2 - line.p1, p - line.p1)) / abs(line.p2 - line.p1);
}

double distanceSP(Line line, Point p) {
    if (sgn(dot(line.p2 - line.p1, p - line.p1)) < 0)
        return abs(p - line.p1);
    if (sgn(dot(line.p1 - line.p2, p - line.p2)) < 0)
        return abs(p - line.p2);
    return distanceLP(line, p);
}

double distanceSS(Line s1, Line s2) {
    if (intersectLS(s1, s2, true))
        return 0;
    double d1 = distanceSP(s1, s2.p1);
    double d2 = distanceSP(s1, s2.p2);
    double d3 = distanceSP(s2, s1.p1);
    double d4 = distanceSP(s2, s1.p2);
    return min({d1, d2, d3, d4});
}
