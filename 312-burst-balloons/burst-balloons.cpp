class Solution {
    int dp[303][303];

    int solve(int s, int e, vector<int>& nums) {
        if (s > e) return 0;
        if (dp[s][e] != -1) return dp[s][e];

        int x = nums[s-1] * nums[e+1];
        int ans = 0;
        for (int i = s; i <= e; ++i) {
            int y = x * nums[i];
            ans = max(ans, y + solve(i+1, e, nums) + solve(s, i-1, nums));
        }
        return dp[s][e] = ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        vector<int> v;
        int n = nums.size();
        v.push_back(1);
        for (int num : nums) {
            v.push_back(num);
        }
        v.push_back(1);

        return solve(1, n, v);
    }
};