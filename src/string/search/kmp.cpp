/*
    文字列検索(KMP法)
    時間計算量 構築O(|P|),検索O(|T|)

    テキストTに含まれるパターンPの開始位置(0-indexed)を列挙する
    正確にはMP法 ***そのうちKMP法にする***

    Usage:
        pattern: 検索するパターンP

        build()で表を構築
        search(text)でtextからpatternを検索

    Verified:
        AOJ ALDS1_14_B String Search
*/

class KMP {
  private:
    string pattern;
    vector<int> table;

  public:
    KMP(string pattern) : pattern(pattern) { table.resize(pattern.size() + 1); }

    void build() {
        int m = pattern.size();
        table[0] = -1;
        for (int j = -1, k = 0; k < m; ++k) {
            while (j >= 0 && pattern[k] != pattern[j])
                j = table[j];
            table[k + 1] = ++j;
        }
    }

    vector<int> search(const string &text) {
        int n = text.size(), m = pattern.size();
        vector<int> res;
        for (int k = 0, i = 0; k + i < n;) {
            if (text[k + i] == pattern[i]) {
                i++;
                if (i == m) {
                    res.push_back(k);
                    k += i - table[i];
                    i = table[i];
                }
            } else {
                k += i - table[i];
                if (i > 0)
                    i = table[i];
            }
        }

        return res;
    }
};
