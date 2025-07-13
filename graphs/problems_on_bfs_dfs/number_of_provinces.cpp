class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        auto dfs = [&](auto&& self, int v) -> void {
            visited[v] = true;
            for (int u = 0; u < n; ++u) {
                if (isConnected[v][u] && !visited[u]) {
                    self(self, u);
                }
            }
        };
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(dfs, i);
                ++count;
            }
        }
        return count;
    }
};
