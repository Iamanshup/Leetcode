class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int best = values[0], ans = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, best + values[i] - i);
            best = max(best, values[i] + i);
        }
        return ans;
    }
};