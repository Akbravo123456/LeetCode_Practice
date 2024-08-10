class Solution {
    void dfs(vector<vector<int>>& grid,int x,int y){
    int n=grid.size();
    if(x<0||x>=n||y<0||y>=n||grid[x][y]==1){
        return;
    }
    grid[x][y]=1;
    dfs(grid,x+1,y);
    dfs(grid,x-1,y);
    dfs(grid,x,y+1);
    dfs(grid,x,y-1);
}
public:
    int regionsBySlashes(vector<string>& grid){
        int n=grid.size();
        vector<vector<int>> matrix(4*n,vector<int>(4*n,0));
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == '/') {
                    matrix[4*i][4*j+3]=1;
                    matrix[4*i+1][4*j+2]=1;
                    matrix[4*i+2][4*j+1]=1;
                    matrix[4*i+3][4*j]=1;
                } else if (grid[i][j] == '\\') {
                    matrix[4*i][4*j]=1;
                    matrix[4*i+1][4*j+1]=1;
                    matrix[4*i+2][4*j+2]=1;
                    matrix[4*i+3][4*j+3]=1;
                }
            }
        }
        int regions=0;
        for (int i=0;i<4*n;i++){
            for (int j=0;j<4*n;j++){
                if (matrix[i][j] == 0){
                    dfs(matrix,i,j);
                    regions++;
                }
            }
        }
        return regions;
    }
};