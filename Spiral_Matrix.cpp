class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int rowBegin=0;
        int rowEnd=n-1;
        int colBegin=0;
        int colEnd=m-1;
        vector<int> ans;
        while(rowBegin<=rowEnd && colBegin<=colEnd){
            if(rowBegin<=rowEnd){
                for(int j=colBegin;j<=colEnd;j++)
                {
                    ans.push_back(matrix[rowBegin][j]);
                }
                rowBegin++;
            }

            if(colBegin<=colEnd){
                for(int i=rowBegin;i<=rowEnd;i++)
                {
                    ans.push_back(matrix[i][colEnd]);
                }
                colEnd--;
            }

            if(rowBegin<=rowEnd){
                for(int j=colEnd;j>=colBegin;j--)
                {
                    ans.push_back(matrix[rowEnd][j]);
                }
                rowEnd--;
            }

            if(colBegin<=colEnd){
                for(int i=rowEnd;i>=rowBegin;i--)
                {
                    ans.push_back(matrix[i][colBegin]);
                }
                colBegin++;
            }

        }
        return ans;
    }
};