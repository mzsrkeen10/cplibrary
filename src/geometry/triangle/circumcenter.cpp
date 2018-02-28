/*
    三角形の外心
    時間計算量 O(1)

    Usage:
        引数に3点を与える

    Verified:
        AOJ0010 Circumscribed Circle of a Triangle
*/

Point circumcenter(Point p1, Point p2, Point p3) {
    double a1, b1, c1, a2, b2, c2, cx, cy;
    a1 = real(p2 - p1);
    b1 = imag(p2 - p1);
    c1 = norm(p2) - norm(p1);
    a2 = real(p3 - p2);
    b2 = imag(p3 - p2);
    c2 = norm(p3) - norm(p2);
    cx = (b2 * c1 - b1 * c2) / (2.0 * (a1 * b2 - a2 * b1));
    cy = (a1 * c2 - a2 * c1) / (2.0 * (a1 * b2 - a2 * b1));
    return Point(cx, cy);
}
