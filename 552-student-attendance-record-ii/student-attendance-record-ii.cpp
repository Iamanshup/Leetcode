class Solution {
private:
    const long long mod = 1e9 + 7;

    int solve(int n, int absent, int late, long long dp[n+1][2][3]) {
        if (n == 0 || absent < 0 || late < 0) return 0;
        if (n == 1) {
            if (absent > 0 && late > 0) return 3;
            if (absent > 0 || late > 0) return 2;
            return 1;
        }
        if (dp[n][absent][late] != -1) {
            return dp[n][absent][late];
        }

        return dp[n][absent][late] = (solve(n-1, absent-1, 2, dp) % mod
                    + solve(n-1, absent, late-1, dp) % mod
                    + solve(n-1, absent, 2, dp) % mod) % mod;
    }


public:
    int checkRecord(int n) {
        long long dp[n+1][2][3];
        memset(dp, -1, sizeof dp);
        return solve(n, 1, 2, dp);
    }
};

