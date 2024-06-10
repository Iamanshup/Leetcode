class Solution {
public:

bool dp[1001];
unordered_map<string, bool> mp;

    bool wordBreak(string s, vector<string>& wordDict) {
        for(string w : wordDict) {
            mp[w] = 1;
        }
        memset(dp, 0, sizeof dp);

        int n = s.size();

        for(int i = 1; i <= n; ++i) {
            if(!dp[i] and mp[s.substr(0, i)]) dp[i] = 1;

            if(dp[i]) {
                for(int j = i+1; j <= n; ++j) {
                    if(!dp[j] and mp[s.substr(i, j-i)]) dp[j] = 1;
                    // if(j == n and dp[j]) return 1;
                }
            }
        }
        return dp[n];
    }
};