class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row=rowSum.size();
        int col=colSum.size();
        int curr_row=0,curr_col=0;
        vector<vector<int>> res(row,vector<int>(col,0));

        while(curr_row<row || curr_col<col){
            if(curr_row>=row){
                res[row-1][curr_col]=colSum[curr_col];
                curr_col++;
                continue;
            }else if(curr_col>=col){
                res[curr_row][col-1]=rowSum[curr_row];
                curr_row++;
                continue;
            }
            int val=min(rowSum[curr_row],colSum[curr_col]);
            rowSum[curr_row] -=val;
            colSum[curr_col] -=val;
            res[curr_row][curr_col]=val;
            if(rowSum[curr_row]==0){
                curr_row++;
            }
            if(colSum[curr_col]==0){
                curr_col++;
            }
        }
        return res;
    }
};