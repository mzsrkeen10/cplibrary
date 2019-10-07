/*
    文字列検索(KMP法)
    時間計算量 構築O(|P|),検索O(|T|)

    テキストTに含まれるパターンPの開始位置(0-indexed)を列挙する

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
        for (int i = 0, j = -1; i < m; ++i) {
            while (j >= 0 && pattern[i] != pattern[j])
                j = table[j];
            j++;
            if (pattern[i + 1] == pattern[j])
                table[i + 1] = table[j];
            else
                table[i + 1] = j;
        }
    }

    vector<int> search(const string &text) {
        int n = text.size(), m = pattern.size();
        vector<int> res;
        for (int i = 0, j = 0; j < n;) {
            while (i > -1 && pattern[i] != text[j])
                i = table[i];
            i++;
            j++;
            if (i >= m) {
                res.push_back(j - i);
                i = table[i];
            }
        }
        return res;
    }
};
