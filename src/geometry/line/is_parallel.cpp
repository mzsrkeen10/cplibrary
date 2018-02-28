/*
    2直線の平行判定(外積)
    時間計算量 O(1)

    Usage:
        2直線を引数に与える

    Verified:
        AOJ0021 Parallelism
*/

#define EPS 1.0e-10

bool is_parallel(Line a, Line b){
    if(sgn(det(a.p1-a.p2, b.p1-b.p2)))return false;
    return true;
}
