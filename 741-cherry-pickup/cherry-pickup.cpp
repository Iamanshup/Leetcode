class Solution {
public:
    int dp[51][51][51];
    int go(vector<vector<int>>& grid, int n, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if (r1 == n || c1 == n || r2 == n || c2 == n
            || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                return INT_MIN;
            }

        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];

        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int cherries = 0;
        if (r1 == r2 && c1 == c2) {
            cherries = grid[r1][c1];
        } else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }
        
        int a1 = go(grid, n, r1+1, c1, r2+1);
        int a2 = go(grid, n, r1, c1+1, r2);
        int a3 = go(grid, n, r1+1, c1, r2);
        int a4 = go(grid, n, r1, c1+1, r2+1);

        return dp[r1][c1][r2] = cherries + max(a1, max(a2, max(a3, a4)));
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp, -1, sizeof dp);
        return max(0, go(grid, n, 0, 0, 0));
    }
};