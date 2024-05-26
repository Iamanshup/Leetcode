class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, vector<pair<int, int>>> mp;

        vector<int> rowMax(m);
        vector<int> colMax(n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mp.find(mat[i][j]) == mp.end()) {
                    pq.push(mat[i][j]);
                }
                mp[mat[i][j]].push_back({i, j});
            }
        }

        vector<vector<int>> temp(m, vector<int>(n, 0));

        while (!pq.empty()) {
            int num = pq.top();
            pq.pop();

            for (auto p : mp[num]) {
                int row = p.first;
                int col = p.second;
                temp[row][col] = 1 + max(rowMax[row], colMax[col]);
            }

            for (auto p : mp[num]) {
                int row = p.first;
                int col = p.second;
                rowMax[row] = max(temp[row][col], rowMax[row]);
                colMax[col] = max(temp[row][col], colMax[col]);
            }
        }

        int ans = 0;
        for (int x : rowMax) ans = max(ans, x);
        for (int x : colMax) ans = max(ans, x);

        return ans;
    }
};