/*
    計算幾何テンプレート

    計算幾何(平面)の基本的な要素
*/

#include <cmath>
#include <complex>
#include <vector>

using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);

using Point = complex<double>;
using Polygon = vector<Point>;

inline int sgn(const double &a) { return (a < -EPS ? -1 : (a > EPS ? 1 : 0)); }

inline bool eq(const Point &a, const Point &b) { return abs(a - b) < EPS; }

inline bool operator<(const Point &a, const Point &b) {
    if (sgn(a.real() - b.real()))
        sgn(a.real() - b.real()) < 0;
    return sgn(a.imag() - b.imag());
}

double dot(const Point &a, const Point &b) { return real(conj(a) * b); }

double det(const Point &a, const Point &b) { return imag(conj(a) * b); }

struct Line {
    Point p1, p2;

    Line(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}

    bool operator<(const Line &rhs) const {
        if (eq(p2, rhs.p2))
            return p1 < rhs.p1;
        return p2 < rhs.p2;
    }
    bool operator==(const Line &rhs) const {
        return (eq(p1, rhs.p1) && eq(p2, rhs.p2)) ||
               (eq(p1, rhs.p2) && eq(p2, rhs.p1));
    }
};
