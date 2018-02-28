/*
    円を表す構造体

    Usage:
        template.cppが必要
*/

struct Circle {
    Point p;
    double r;
    Circle(Point p = Point(), double r = 0) : p(p), r(r) {}
};
