class Solution {
public:
    void addSolution(vector<vector<string>> &ans, vector<vector<int>> &board, int n) {
        vector<string> temp;
        for (int i = 0; i < n; ++i) {
            string row = "";
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 1)
                    row += 'Q';
                else
                    row += '.';
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        int i, j;

        for (i = 0; i < col; ++i)
            if (board[row][i])
                return false;

        for (i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j])
                return false;

        for (i = row, j = col; j >= 0 && i < n; ++i, --j)
            if (board[i][j])
                return false;

        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n) {
        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (isSafe(i, col, board, n)) {
                board[i][col] = 1;
                solve(col + 1, ans, board, n);
                board[i][col] = 0; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};