class Solution {
private:
    bool canMakeValidSubstring(int substringSize, string s, int k) {
        vector<int> freq(26);
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            freq[s[i] - 'A']++;

            if (i >= substringSize) {
                freq[s[i - substringSize] - 'A']--;
            }

            int mx = 0;
            for (int f : freq) {
                mx = max(mx, f);
            }

            if (substringSize - mx <= k) {
                return true;
            }
        }
        return false;
    }

public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 1, high = n+1;

        while (low <= high-2) {
            int mid = low + (high - low) / 2;
            if (canMakeValidSubstring(mid, s, k)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};