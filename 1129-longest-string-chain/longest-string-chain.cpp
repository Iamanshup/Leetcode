class Solution {
private:
    bool isPredecessor(string s1, string s2) {
        if (s1.size() + 1 != s2.size()) return false;
        
        if (s1 == s2.substr(1) || s1 == s2.substr(0, s2.size()-1)) {
            return true;
        }

        int ind = 0;
        while (ind < s1.size() && s1[ind] == s2[ind]) ++ind;
        return s1.substr(ind) == s2.substr(ind+1);
    }

    int getPathLength(string node, unordered_map<string, int>& pathLength, unordered_map<string, unordered_set<string>>& graph) {
        if (pathLength.find(node) != pathLength.end()) {
            return pathLength[node];
        }

        int ans = 0;
        for (string adj : graph[node]) {
            ans = max(ans, getPathLength(adj, pathLength, graph));
        }
        return pathLength[node] = 1 + ans;
    }

public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, unordered_set<string>> mp;
        for (string w : words) {
            mp[w.size()].insert(w);
        }

        unordered_map<string, unordered_set<string>> graph;

        for (int i = 0; i < mp.size() - 1; ++i) {
            unordered_set<string> st1 = mp[i];
            unordered_set<string> st2 = mp[i+1];
            for (string s1 : st1) {
                for (string s2 : st2) {
                    if (isPredecessor(s1, s2)) {
                        graph[s1].insert(s2);
                    }
                }
            }
        }

        unordered_map<string, int> pathLength;

        int ans = 0;
        sort(words.begin(), words.end());
        for (auto w : words) {
            if (pathLength.find(w) == pathLength.end()) {
                ans = max(ans, getPathLength(w, pathLength, graph));
            }
        }
        return ans;
    }
};