class Solution {
public:
    int racecar(int target) {
        static vector<int> dp(10001, -1);
        if (dp[target] != -1) return dp[target];

        int n = floor(log2(target)) + 1;

        if ((1 << n) - 1 == target) return dp[target] = n;

        dp[target] = n + 1 + racecar((1 << n) - 1 - target);
        for (int i = 0; i <= n-2; ++i) {
            dp[target] = min(dp[target], n + i + 1 + racecar(target - (1 << n-1) + (1 << i)));
        }
        return dp[target];
    }
};