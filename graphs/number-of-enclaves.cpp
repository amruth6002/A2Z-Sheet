class Solution {
public:
    void dfs(vector<vector<int>> &v, int i, int j) {
        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] != 1) {
            return;
        }
        v[i][j] = -1;
        dfs(v, i, j + 1);
        dfs(v, i, j - 1);
        dfs(v, i + 1, j);
        dfs(v, i - 1, j);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                dfs(grid, i, 0);
            }
            if (grid[i][n - 1] == 1) {
                dfs(grid, i, n - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                dfs(grid, 0, i);
            }
            if (grid[m - 1][i] == 1) {
                dfs(grid, m - 1, i);
            }
        }
        int ans=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans++;
                } 
            }
        }
        return ans;
    }
};
