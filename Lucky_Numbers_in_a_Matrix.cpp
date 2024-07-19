class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       int n=matrix.size(),m=matrix[0].size(); 
       int rmm=0;
       for(auto& n:matrix){
        rmm=max(*min_element(n.begin(),n.end()),rmm);
       }
       int cmm=INT_MAX;
       for(int col_idx=0;col_idx<m;col_idx++){
        int col_max=0;
        for(int row_idx=0;row_idx<n;row_idx++){
            col_max=max(col_max,matrix[row_idx][col_idx]);
        }
        cmm=min(col_max,cmm);
       }
       return rmm==cmm?vector<int>{cmm}:vector<int>{};
    }
};