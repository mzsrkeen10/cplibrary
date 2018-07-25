/*
    点・線間の距離
    時間計算量 O(1)

    Usage:
        点・線などを引数に与える
        template.cppが必要

    Verified:
        null
*/

double distanceLP(Line line, Point p){
    return abs(det(line.p2-line.p1, p-line.p1)) / abs(line.p2-line.p1);
}

double distanceSP(Line line, Point p){
    if(sgn(dot(line.p2-line.p1, p-line.p1)) < 0) return abs(p-line.p1);
    if(sgn(dot(line.p1-line.p2, p-line.p2)) < 0) return abs(p-line.p2);
    return distanceLP(line, p);
}
