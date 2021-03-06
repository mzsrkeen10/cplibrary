/*
    編集距離(レーベンシュタイン距離)
    時間計算量 O(|S1||S2|)

    Usage:
        2つの文字列を引数に与える

    Verified:
        AOJ DPL_1_E Edit Distance (Levenshtein Distance)
*/

#include <algorithm>
#include <string>
#include <vector>

constexpr int INF = 1e9;

int edit_distance(std::string s1, std::string s2) {
    std::vector<std::vector<int>> dp(s1.size() + 1,
                                     std::vector<int>(s2.size() + 1, INF));

    for (int i = 0; i <= s1.size(); ++i)
        dp[i][0] = i;
    for (int j = 0; j <= s2.size(); ++j)
        dp[0][j] = j;

    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            dp[i][j] =
                std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                          dp[i - 1][j - 1] + !!(s1[i - 1] != s2[j - 1])});
        }
    }

    return dp[s1.size()][s2.size()];
}
