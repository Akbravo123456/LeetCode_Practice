class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxgold=0;
        
        function<int(int,int)> helper=[&](int row,int col)->int{
            if(row<0||row>=m || col<0||col>=n || grid[row][col]==0){
                return 0;
            }

            int curr=grid[row][col];
            grid[row][col]=0;

            int a=helper(row+1,col);
            int b=helper(row-1,col);
            int c=helper(row,col+1);
            int d=helper(row,col-1);

            grid[row][col]=curr;
            return curr+max({a,b,c,d});
        };

        for(int row=0;row<m;row++){
            for (int col=0;col<n;col++) {
                if(grid[row][col]>0){
                    maxgold=max(maxgold,helper(row,col));
                }
        }
    }
    return maxgold;
    }
};