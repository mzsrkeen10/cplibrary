/*
    桁DP

    AtCoder ABC007-D 禁止された数字
*/

#define rep(i, a) for (int i = 0; i < (int)(a); ++i)

long long int solve(string s) {
    long long int dp[20][2][2] = {1};
    rep(i, s.size()) rep(j, 2) rep(k, 2) {
        int lim = j ? 9 : s[i] - '0';
        rep(d, lim + 1) {
            dp[i + 1][j || d < lim][k || d == 4 || d == 9] += dp[i][j][k];
        }
    }
    long long int ans = 0;
    rep(j, 2) ans += dp[s.size()][j][1];
    return ans;
}
