/*
    三角形の内外判定
    時間計算量 O(1)

    Usage:
        引数に三角形の頂点の座標と判定したい点の座標を与える
        点及び辺上は外部として判定される
*/

#define EPS 1.0e-9

bool is_in_a_triangle(double ax, double ay, double bx, double by, double cx,
                      double cy, double px, double py) {
    double c1 = (bx - ax) * (py - ay) - (by - ay) * (px - ax);
    double c2 = (cx - bx) * (py - by) - (cy - by) * (px - bx);
    double c3 = (ax - cx) * (py - cy) - (ay - cy) * (px - cx);
    if (c1 + EPS > 0 && c2 + EPS > 0 && c3 + EPS > 0)
        return true;
    else if (c1 + EPS < 0 && c2 + EPS < 0 && c3 + EPS < 0)
        return true;
    else
        return false;
}
