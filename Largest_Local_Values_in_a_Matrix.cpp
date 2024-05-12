class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
       int n=grid.size();
       vector<vector<int>> res(n-2,vector<int>(n-2));
       for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            int temp=0;

            for(int a=i-1;a<=i+1;a++){
                for(int b=j-1;b<=j+1;b++){
                    temp=max(temp,grid[a][b]);
                }
            }
            res[i-1][j-1]=temp;
        }
       } 
       return res;
    }
};