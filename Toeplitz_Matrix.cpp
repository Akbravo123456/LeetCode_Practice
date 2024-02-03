class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size(); // Fix: Use the correct variable for column size

        for (int i = 0; i < m; i++) {
            int top = matrix[0][i];
            int x = 1;
            int y = i + 1;

            while (x < n && y < m) {
                if (matrix[x][y] != top)
                    return false;
                x++;
                y++;
            }
        }

        for (int i = 1; i < n; i++) {
            int top = matrix[i][0];
            int x = i + 1;
            int y = 1;

            while (x < n && y < m) {
                if (matrix[x][y] != top)
                    return false;
                x++;
                y++;
            }
        }

        return true;
    }
};