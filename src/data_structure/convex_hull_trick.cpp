/*
    Convex Hull Trick
    時間計算量 O((N+Q)log N)
    (直線の傾きとクエリに単調性がある場合O(N))

    直線集合 L = {f_i(x) = a_i * x + b_i}に対して,以下のクエリを高速で行う
    1. 直線 f_k(x) = a_k * x + b_k の追加
    2. あるxに対し, min(f_i(x))またはmax(f_i(x))を求める

    *** max()のクエリ及び単調性がない場合のCHTは未実装 ***
*/

#include <deque>
#include <utility>

// 単調性がある場合
class ConvexHullTrick {
    using ll = long long int;
    using Line = std::pair<ll, ll>;

  private:
    std::deque<Line> lines;

  public:
    bool check(Line a, Line b, Line c) {
        return (c.second - b.second) * (b.first - a.first) >=
               (b.second - a.second) * (c.first - b.first);
    }

    void add(ll a, ll b) {
        Line line = make_pair(a, b);
        while (lines.size() >= 2 &&
               check(lines[lines.size() - 2], lines.back(), line))
            lines.pop_back();
        lines.push_back(line);
    }

    ll f(ll i, ll x) { return lines[i].first * x + lines[i].second; }

    ll get(ll x) {
        assert(lines.size());
        while (lines.size() >= 2 && f(0, x) >= f(1, x)) {
            lines.pop_front();
        }
        return f(0, x);
    }
};

// 単調性が無い場合
class ConvexHullTrick{
    using ll = long long int;

    struct Line {
        ll slope, intercept, left;
    };

    struct CompareBySlope {
        bool operator() (const Line &lhs, const Line &rhs) {
            return lhs.slope < rhs.slope;
        }
    };

    struct CompareByLeft {
        bool operator() (const Line &lhs, const Line &rhs) {
            return lehs.left < rhs.left;
        }
    };

private:
    std::set<Line, CompareBySlope> lines_s;
    std::set<Line, CompareByLeft> lines_l;

public:
    bool check(Line a, Line b, Line c) {
        return (c.intercept - b.intercept) * (b.slope - a.slope) >=
               (b.intercept - a.intercept) * (c.slope - b.slope);
    }

    void add(ll a, ll b) {
        Line line = (Line){a, b, 0};
        auto it = 
    }

    ll f(ll i, ll x) { return lines[i].first * x + lines[i].second; }

    ll get(ll x) {
        assert(lines.size());
        while (lines.size() >= 2 && f(0, x) >= f(1, x)) {
            lines.pop_front();
        }
        return f(0, x);
    }
};
