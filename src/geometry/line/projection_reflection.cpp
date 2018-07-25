/*
    点の直線への射影・直線に関して対称な点
    時間計算量 O(1)

    Usage:
        直線と点を引数に与える
        template.cppが必要

    Verified:
        AOJ CGL_1_A Projection
        AOJ CGL_1_B Reflection
*/

Point projection(Line line, Point p) {
    Point a = line.p2 - line.p1, b = p - line.p1;
    double r = dot(a, b) / norm(a);
    return line.p1 + r * a;
}

Point reflection(Line line, Point p) {
    Point proj = projection(line, p);
    return p + (proj - p) * 2.;
}
