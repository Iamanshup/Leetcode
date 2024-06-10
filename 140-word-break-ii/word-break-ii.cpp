class Solution {
private:
    void solve(int ind, string s, vector<string>& wordDict, string ss, vector<string> &ans) {
        int n = s.size();
        if (ind == n) {
            ans.push_back(ss);
            return;
        }

        for (string w : wordDict) {
            if (w.size() > n - ind) continue;
            if (s.substr(ind, w.size()) == w) {
                string sss = ss;
                if (ss == "") sss = w;
                else sss = ss + " " + w;
                solve(ind + w.size(), s, wordDict, sss, ans);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        solve(0, s, wordDict, "", ans);
        return ans;
    }
};