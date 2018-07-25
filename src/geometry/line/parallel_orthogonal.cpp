/*
    2直線の平行・垂直判定
    時間計算量 O(1)

    Usage:
        2直線を引数に与える
        template.cppが必要

    Verified:
        AOJ0021 Parallelism
        AOJ CGL_2_A Parallel/Orthogonal
*/

bool is_parallel(Line a, Line b) {
    if (sgn(det(a.p1 - a.p2, b.p1 - b.p2)))
        return false;
    return true;
}

bool is_orthogonal(Line a, Line b) {
    if (sgn(dot(a.p1 - a.p2, b.p1 - b.p2)))
        return false;
    return true;
}
