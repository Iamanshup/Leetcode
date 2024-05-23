class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> track(100000);
        vector<int> ans;

        for (vector<int> v : paint) {
            int start = v[0];
            int end = v[1];
            int cur = 0;

            while (start < end) {
                if (track[start] == 0) {
                    track[start] = end;
                    ++cur;
                    ++start;
                } else {
                    start = track[start];
                }
            }
            ans.push_back(cur);
        }

        return ans;
    }
};