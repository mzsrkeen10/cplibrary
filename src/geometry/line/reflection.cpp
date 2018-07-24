/*
    直線に関して対称な点
    時間計算量 O(1)

    Usage:
        直線と点を引数に与える
        template.cpp, projection.cppが必要

    Verified:
        AOJ CGL_1_B Reflection
 */

Point reflection(Line line, Point p) {
    Point proj = projection(line, p);
    return p + (proj - p) * 2.;
}
