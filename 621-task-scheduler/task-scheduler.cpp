class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);

        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        sort(freq.rbegin(), freq.rend());

        int maxFreeSlots = (freq[0] - 1) * n;

        for (int i = 1; i < 26; ++i) {
            maxFreeSlots -= min(freq[i], freq[0]-1);
        }

        return maxFreeSlots > 0 ? maxFreeSlots + tasks.size() : tasks.size();
    }
};