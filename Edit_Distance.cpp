class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> costDP(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) 
            costDP[i][0] = i;
        
        for (int j = 1; j <= n; j++) 
            costDP[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    costDP[i][j] = costDP[i - 1][j - 1];
                } else {
                    int topLeft = costDP[i - 1][j - 1];
                    int top = costDP[i - 1][j];
                    int left = costDP[i][j - 1];
                    costDP[i][j] = min(topLeft, min(top, left)) + 1;
                }
            }
        }
        return costDP[m][n];
    }
};
