/*
    最長共通接頭辞(Z-algorithm)
    時間計算量 O(|S|)

    文字列Sに対し，SとS[i:|S|-1]の最長共通接頭辞の長さを求める

    Usage:
        文字列Sを引数に与える

    Verified:
        ABC 141 E Who Says a Pun?
*/

#include <algorithm>
#include <string>
#include <vector>

std::vector<int> z_algorithm(const std::string &s) {
    std::vector<int> prefix(s.size());
    for (int i = 1, j = 0; i < (int)s.size(); i++) {
        if (i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = std::max(0, j + prefix[j] - i);
            while (i + k < (int)s.size() && s[k] == s[i + k])
                k++;
            prefix[i] = k;
            j = i;
        }
    }
    prefix[0] = (int)s.size();
    return prefix;
}
