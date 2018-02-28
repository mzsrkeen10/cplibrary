/*
    凸包(Andrew's Monotone Chain)
    時間計算量 O(nlog n)

    点集合に対してその凸包を求める

    Usage:
        引数に点集合を与える
        template.cpp, ccw.cppが必要

    Verified:
        AOJ CGL_4_A Convex Hull
*/

Polygon convex_hull(Polygon s) {
    int n = s.size(), k = 0;
    if (n < 3)
        return s;
    sort(s.begin(), s.end());

    Polygon ch(2 * n);

    // 下側凸包
    for (int i = 0; i < n; i++) {
        while (k >= 2 && ccw(ch[k - 2], ch[k - 1], s[i]) == CLOCKWISE)
            k--;
        ch[k++] = s[i];
    }

    // 上側凸包
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && ccw(ch[k - 2], ch[k - 1], s[i]) == CLOCKWISE)
            k--;
        ch[k++] = s[i];
    }

    ch.resize(k - 1);
    return ch;
}
