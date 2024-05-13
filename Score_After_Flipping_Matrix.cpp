class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        auto fliprow=[&](int row){
            for(int col=0;col<cols;col++){
                grid[row][col] ^=1;
            }
        };

        auto flipcol=[&](int col){
            for(int row=0;row<rows;row++){
                grid[row][col] ^=1;
            }
        };

         auto checkRow = [&](const vector<int>& nums) {
            int result = 0;
            for (int num : nums) {
                result = result * 2 + num;
            }
            return result;
         };

        for (int row=0; row<rows;row++) {
            if (grid[row][0] == 0) {
                fliprow(row);
            }
        }

        for(int col=1;col<cols;col++){
            int countone=0;
            for (int row=0;row<rows;row++){
                if(grid[row][col]==1){
                    countone++;
                }
        }
        if(countone *2<rows){
            flipcol(col);
        }
    }

    int totalScore = 0;
        for (const auto& row:grid) {
            totalScore += checkRow(row);
        }
        return totalScore;
    }
};