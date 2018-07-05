/*
    区間DP

    AOJ 1611 ダルマ落とし
*/

int dp[302][302];

for (int i = 0; i <= 300; ++i)
    for (int j = 0; j <= 300; ++j)
        dp[i][j] = 0;

for (int i = 0; i < n - 1; ++i) {
    if (abs(v[i] - v[i + 1]) <= 1)
        dp[i][i + 1] = 2;
}

for (int k = 2; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        if (i + k >= n)
            break;
        for (int j = 0; j < k; ++j)
            dp[i][i + k] =
                max(dp[i][i + k], dp[i][i + j] + dp[i + j + 1][i + k]);
        if (dp[i + 1][i + k - 1] == k - 1 && abs(v[i] - v[i + k]) <= 1)
            dp[i][i + k] = k + 1;
        dp[i][i + k] = max(dp[i][i + k], dp[i + 1][i + k - 1]);
    }
}
