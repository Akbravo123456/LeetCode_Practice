class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num=1;
        int rowBegin=0,rowEnd=n-1;
        int colBegin=0,colEnd=n-1;
        while (rowBegin<= rowEnd && colBegin<= colEnd){
            for (int i=colBegin;i<=colEnd;i++){
                matrix[rowBegin][i]=num++;
            }rowBegin++;

            for (int i=rowBegin;i<=rowEnd;i++){
                matrix[i][colEnd]=num++;
            }colEnd--;

            if(rowBegin<=rowEnd){
                for(int i=colEnd;i>=colBegin;i--){
                    matrix[rowEnd][i] = num++;
                }
            }rowEnd--;
            if(colBegin<=colEnd){
            for (int i = rowEnd; i >= rowBegin; i--) {
                matrix[i][colBegin] = num++;
            }
        }
          colBegin++;
        }
        return matrix;
    }
};