class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<string, int>>> v(26);

        for (string w : words) {
            int pos = w[0] - 'a';
            v[pos].push_back({w, 0});
        }
        int ans = 0;

        for (char ch : s) {
            int pos = ch - 'a';

            int n = v[pos].size();
            vector<pair<string, int>> vv = v[pos];
            v[pos].clear();
            for (int i = 0; i < n; ++i) {
                vv[i].second++;
                string w = vv[i].first;
                int ind = vv[i].second;
                
                if (ind == w.size()) ++ans;
                else v[w[ind] - 'a'].push_back({w, ind}); 
            }
        }
        return ans;
    }
};