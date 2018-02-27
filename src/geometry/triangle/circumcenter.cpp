/*
    三角形の外心
    時間計算量 O(1)

    Usage:
        引数に3点の座標と外心の座標受け取る変数を与える

    Verified:
        AOJ0010 Circumscribed Circle of a Triangle
*/

void circumcenter(double x1, double y1, double x2, double y2, double x3,
                  double y3, double &cx, double &cy) {
    double a1, b1, c1, a2, b2, c2;
    a1 = x2 - x1;
    b1 = y2 - y1;
    c1 = x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1;
    a2 = x3 - x2;
    b2 = y3 - y2;
    c2 = x3 * x3 - x2 * x2 + y3 * y3 - y2 * y2;
    cx = (b2 * c1 - b1 * c2) / (2.0 * (a1 * b2 - a2 * b1));
    cy = (a1 * c2 - a2 * c1) / (2.0 * (a1 * b2 - a2 * b1));
}
