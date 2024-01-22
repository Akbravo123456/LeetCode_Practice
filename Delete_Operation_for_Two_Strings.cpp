class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        int length = lcs(word1, word2);
        return word1.length() + word2.length() - 2 * length;
    }

private:
    int lcs(const string& text1, const string& text2) {
        vector<vector<int>> dp(text1.length() + 1,vector<int>(text2.length() + 1, 0));

        for (int i = 0; i <= text1.length(); ++i) {
            for (int j = 0; j <= text2.length(); ++j) {
                if (i == 0 || j == 0) {
                    continue;
                }

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] =max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.length()][text2.length()];
    }
};