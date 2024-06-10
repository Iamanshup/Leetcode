class Solution {
private:
    int dp[3001];

    bool solve(int ind, string s, vector<string>& wordDict) {
        int n = s.size();
        if (ind == n) return true;
        if (dp[ind] != -1) return dp[ind];

        bool f = false;
        for (string w : wordDict) {
            if (w.size() > n - ind) continue;
            if (s.substr(ind, w.size()) == w) {
                f |= solve(ind + w.size(), s, wordDict);
            }
        }
        return dp[ind] = f;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof dp);
        return solve(0, s, wordDict);
    }
};