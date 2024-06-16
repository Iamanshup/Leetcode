class Solution {
public:
    int dp[2001][2001];

    bool go(string &s, string &p, int i, int j) {
        if (i < 0 && j < 0) return 1;
        if (i >= 0 && j < 0) return 0;
        if (i < 0 && j >= 0) {
            for (int ind = 0; ind <= j; ++ind) {
                if (p[ind] != '*') return 0;
            }
            return 1;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (p[j] == '?' || p[j] == s[i]) {
            return dp[i][j] = go(s, p, i-1, j-1);
        } else if (p[j] == '*') {
            return dp[i][j] = go(s, p, i-1, j) || go(s, p, i, j-1);
        }

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof dp);
        return go(s, p, s.size()-1, p.size()-1);
    }
};