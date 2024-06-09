class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ind = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= nums[0]) {
                l = m + 1;
            } else {
                ind = m;
                r = m - 1;
            }
        }

        return nums[ind];
    }
};