/*
    点の進行方向

    3点p0,p1,p2に対して,p0->p1->p2と進む時,
    - p0->p1で時計方向に折れてp1->p2 (CLOCKWISE)
    - p0->p1で反時計方向に折れてp1->p2 (COUNTER_CLOCKWISE)
    - p0->p1で逆を向いてp0を通り越してp1->p2 (ONLINE_BACK)
    - p0->p1でそのままp1->p2 (ONLINE_FRONT)
    - p0->p1で逆を向いてp1->p2 (ON_SEGMENT)
    のいずれかを判定する

    ONLINE_FRONT
         .p2
        /
       .p1
      /
     /
    .p0

    CLOCKWISE
       .p1
      /     . p2
     /   ／
    / ／
    .p0

    ON_SEGMENT
         .p1
        /
       .p2
      /
     /
    .p0

    COUNTER_CLOCKWISE
        .p2
       /     . p1
      /   ／
     / ／
    .p0

    ONLINE_BACK
         .p1
        /
       .p0
      /
     /
    .p2

    Usage:
        引数に3点を与える
        template.cppが必要

    Verified:
        AOJ CGL_1_C Counter-Clockwise
*/

enum CCW {
    ONLINE_FRONT = -2,
    CLOCKWISE,
    ON_SEGMENT,
    COUNTER_CLOCKWISE,
    ONLINE_BACK
};

int ccw(Point p0, Point p1, Point p2) {
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (sgn(det(a, b)) == 1)
        return COUNTER_CLOCKWISE;
    if (sgn(det(a, b)) == -1)
        return CLOCKWISE;
    if (sgn(dot(a, b)) == -1)
        return ONLINE_BACK;
    if (sgn(norm(b) - norm(a)) == 1)
        return ONLINE_FRONT;
    return ON_SEGMENT;
}
