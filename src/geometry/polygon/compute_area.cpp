/*
    多角形の面積
    時間計算量 O(n)

    Usage:
        多角形を引数に与える
        多角形の頂点は時計回りまたは反時計回りに結ばれているものとしている
        template.cppが必要

    Verified:
        AOJ CGL_3_A Area
*/

double compute_area(Polygon &poly) {
    double res = 0;
    for (int i = 0; i < poly.size(); i++) {
        res += det(poly[i], poly[(i + 1) % poly.size()]);
    }
    return abs(res) / 2.0;
}
