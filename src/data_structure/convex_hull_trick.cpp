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

class ConvexHullTrick {
    using i64 = int64_t;
    using Line = std::pair<i64, i64>;

  private:
    std::deque<Line> lines;

  public:
    bool check(Line a, Line b, Line c) {
        return (c.second - b.second) * (b.first - a.first) >=
               (b.second - a.second) * (c.first - b.first);
    }

    void add(i64 a, i64 b) {
        Line line = make_pair(a, b);
        while (lines.size() >= 2 &&
               check(lines[lines.size() - 2], lines.back(), line))
            lines.pop_back();
        lines.push_back(line);
    }

    i64 f(i64 i, i64 x) { return lines[i].first * x + lines[i].second; }

    i64 get(i64 x) {
        assert(lines.size());
        while (lines.size() >= 2 && f(0, x) >= f(1, x)) {
            lines.pop_front();
        }
        return f(0, x);
    }
};
