/*
    三角形の内接円（内心，半径）
    時間計算量 O(1)

    Usage:
        引数に3点を与える
        template.cppが必要

    Verified:
        *** not verified ***
*/

Point incenter(Point p1, Point p2, Point p3) {
    double x = abs(p2 - p3), y = abs(p3 - p1), z = abs(p1 - p2);
    Point c = (x * p1 + y * p2 + z * p3) / (x + y + z);
    return c;
}

double inradius(Point p1, Point p2, Point p3) {
    double x = abs(p2 - p3), y = abs(p3 - p1), z = abs(p1 - p2);
    double s = abs(det(p1 - p2, p2 - p3)) / 2.0;
    return 2 * s / (x + y + z);
}
