/*
    Binary Indexed Tree
    時間計算量 O(log n)

    整数列a_1, a_2, ..., a_nに対して,以下のクエリを高速に行う.
    1. sum(i): a_1 + a_2 + ... + a_i
    2. add(i, x): a_i に x を加える

    Usage:
        1-indexedになっているので注意

    Verified:
        AOJ DSL_2_B Range Sum Query
*/

#include <vector>

class BIT {
  private:
    int n;
    std::vector<int> bit;

  public:
    BIT(int n) : n(n) {
        bit.resize(n+1);
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};
