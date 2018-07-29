/*
    単純多角形の凸性判定
    時間計算量 O(n)

    多角形が(広義)凸であるか判定する

    Usage:
        多角形を引数に与える
        多角形の頂点は時計回りまたは反時計回りに結ばれているものとしている
        template.cpp, ccw.cppが必要

        狭義凸性の判定を行う場合は,ONLINE_FRONTを許容しないようにし,
        頂点数3の場合分けを消去する

    Verified:
        AOJ CGL_3_B Is-Convex
*/

bool is_convex(const Polygon &poly) {
    if (poly.size() < 3)
        return false;
    if (poly.size() == 3)
        return true;
    int r = 0;
    for (int i = 0; i < poly.size(); i++) {
        int c = ccw(prev(poly, i), curr(poly, i), next(poly, i));
        if (r == 0 && abs(c) == 1)
            r = c;
        if (c != ONLINE_FRONT && c * r != 1)
            return false;
    }
    return true;
}
