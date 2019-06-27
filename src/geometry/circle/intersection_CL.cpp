/*
    円と直線の交点
    時間計算量 O(1)

    Usage:
        円と直線を引数に与える
        template.cpp, circle.cpp,
        line/distance.cpp, line/projection_reflection.cpp
        が必要

    Verified:
        AOJ CGL_7_D Cross Points of a Circle and a Line
*/

vector<Point> intersection(Circle c, Line line) {
    double d = distanceLP(line, c.p);
    vector<Point> res;
    if (sgn(d - c.r) > 0)
        return res;
    Point p = projection(line, c.p);
    if (eq(d, c.r)) {
        res.push_back(p);
        return res;
    }
    double len = sqrt(c.r * c.r - d * d);
    Point e = (line.p1 - line.p2) / abs(line.p1 - line.p2);
    res.push_back(p + len * e);
    res.push_back(p + len * e * Point(-1, 0));
    if (res[1] < res[0])
        swap(res[0], res[1]);
    return res;
}
