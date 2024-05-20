class Solution {
    unordered_map<int, int> dp;
    int solve(int num) {
        if (num == 1) return 0;
        if (dp.find(num) != dp.end()) return dp[num];

        if (num&1) {
            return dp[num] = 1 + solve(3 * num + 1);
        } else {
            return dp[num] = 1 + solve(num / 2);
        }
    }

public:
    int getKth(int lo, int hi, int k) {
        dp.clear();
        vector<int> v;
        for (int i = lo; i <= hi; ++i) v.push_back(i);
        sort(v.begin(), v.end(), [&](int a, int b) {
            int x = solve(a);
            int y = solve(b);
            if (x != y) return x < y;
            return a < b;
        });
        return v[k-1];
    }
};