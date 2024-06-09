class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);
        }
        vector<int> ans;
        ans.push_back(q[0]);
        for (int i = k; i < n; ++i) {
            int lastNum = nums[i - k];
            if (q.front() == lastNum) q.pop_front();
            
            while (!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);
            ans.push_back(q[0]);
        }
        return ans;
    }
};