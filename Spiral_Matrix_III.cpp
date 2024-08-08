class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total = rows*cols;
        result.push_back({rStart, cStart});
        int count=1;
        int step=1;
        int r=rStart,c=cStart;
        while(count<total){
            for (int i=0;i<step;i++){
                c++;
                if (c>=0 && c<cols && r>=0 && r<rows){
                    result.push_back({r,c});
                    count++;
                }
            }
            for (int i=0;i<step;i++) {
                r++;
                if (c>=0 && c<cols && r>=0 && r<rows){
                    result.push_back({r,c});
                    count++;
                }
            }
            step++;
            for (int i=0;i<step;i++){
                c--;
                if (c>=0 && c<cols && r>=0 && r<rows){
                    result.push_back({r,c});
                    count++;
                }
            }
            for (int i=0;i<step;i++){
                r--;
                if (c >=0 && c<cols && r>= 0 && r<rows){
                    result.push_back({r,c});
                    count++;
                }
            }   
            step++;
        }
        return result;
    }
};
