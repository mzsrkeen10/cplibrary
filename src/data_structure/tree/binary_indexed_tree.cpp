/*
    Binary Indexed Tree
    時間計算量 O(log n)

    整数列a_1, a_2, ..., a_nに対して,以下のクエリを高速に行う.
    1. sum(i): a_1 + a_2 + ... + a_i
    2. add(i, x): a_i に x を加える
*/

#include <vector>

class BIT {
  private:
    int n;
    std::vector<int> bit;

  public:
    BIT(int n) {
        this->n = n;
        for (int i = 0; i <= n; ++i)
            bit.push_back(0);
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
