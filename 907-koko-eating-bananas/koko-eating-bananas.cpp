class Solution {
private:
    bool isPossible (vector<int>& piles, int k, int h) {
        long t = 0;
        for (int p : piles) {
            t += ceil(p / (double)k);
        }
        return t <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};