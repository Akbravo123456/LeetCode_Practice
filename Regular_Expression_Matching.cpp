class Solution {
public:
    bool isMatch(string s, string p) {
        int rows = s.length();
        int columns = p.length();

        if (rows == 0 && columns == 0){
            return true;
        }
        if (columns == 0){
            return false;
        }
        vector<vector<bool>> dp(rows + 1, vector<bool>(columns + 1,false));

        dp[0][0]=true;

        for(int i=2; i <= columns; i++){
            if (p[i - 1] == '*'){
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= columns; j++){
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.'){
                    dp[i] [j] =dp[i - 1][j - 1];
                }
                else if (j > 1 && p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]){
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[rows][columns];
    }
};