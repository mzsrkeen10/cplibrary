/*
    KD Tree
    時間計算量 ?

    Usage:
        insert()で点を追加
        search()で最近傍を探索

    Verified:
        *** not verified ***
*/

using Point = pair<int, int>;

class KDTree {
  private:
    struct Node {
        Point p;
        Node *l, *r;
        Node(const Point &p) : p(p), l(nullptr), r(nullptr) {}
    } * root;

    bool compare(int d, Point p, Point q) {
        return (d ? p.first < q.first : p.second < q.second);
    }

  public:
    KDTree() : root(nullptr) {}

    void insert(const Point &p) { root = insert(root, 0, p); }

    Node *insert(Node *t, int d, const Point &p) {
        if (t == nullptr)
            return new Node(p);
        if (compare(d, p, t->p))
            t->l = insert(t->l, !d, p);
        else
            t->r = insert(t->r, !d, p);
        return t;
    }

    int search(const Point &query) {
        int min_dist = INT_MAX;
        search(root, 0, query, &min_dist);
        return min_dist;
    }

    void search(Node *t, int d, const Point &query, int *min_dist) {
        if (t == nullptr)
            return;
        const Point &p = t->p;
        const int dist =
            abs(p.first - query.first) + abs(p.second - query.second);
        *min_dist = min(*min_dist, dist);
        if (!compare(d, p, query))
            search(t->l, !d, query, min_dist);
        else
            search(t->r, !d, query, min_dist);
        int diff =
            (d ? abs(p.first - query.first) : abs(p.second - query.second));
        if (diff < *min_dist) {
            if (compare(d, p, query))
                search(t->l, !d, query, min_dist);
            else
                search(t->r, !d, query, min_dist);
        }
    }
};
