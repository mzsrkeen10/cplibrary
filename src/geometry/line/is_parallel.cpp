/*
    2直線の平行判定(外積)
    時間計算量 O(1)

    Usage:
        4点の座標を引数に与える
*/

#define EPS 1.0e-10

bool is_parallel(double ax, double ay, double bx, double by, double cx,
                 double cy, double dx, double dy) {
    double cp = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
    return fabs(cp) < EPS;
}
