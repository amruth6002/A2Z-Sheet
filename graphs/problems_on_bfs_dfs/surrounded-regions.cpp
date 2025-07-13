class Solution {
public:
    void dfs(vector<vector<char>> &v, int i, int j) {
        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] != 'O') {
            return;
        }
        v[i][j] = 'K';
        dfs(v, i, j + 1);
        dfs(v, i, j - 1);
        dfs(v, i + 1, j);
        dfs(v, i - 1, j);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'K') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
