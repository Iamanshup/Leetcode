class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        bool dp[m+1][n+1];
        memset(dp, false, sizeof dp);

        dp[0][0] = 1;
        for(int i = 2; i <= n; i += 2) {
            if(p[i-1] == '*') dp[0][i] = dp[0][i-1] = dp[0][i-2];
        }

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(p[j-1] == '.' or s[i-1] == p[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2] == '.' or s[i-1] == p[j-2])
                        dp[i][j] |= dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};