class Solution {
    static constexpr int dir[4][2]={{0, 1},{1, 0},{0, -1},{-1, 0}};
    bool isDisconnected(vector<vector<int>>& grid) {
        int islands = 0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0 || visited[i][j]){
                    continue;
                }
                if(islands++>1){
                    return true;
                }
                dfs(grid,i,j,visited);
            }
        }
        return islands!=1;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited) {
        visited[i][j]=true;
        for(const auto& [dx,dy]:dir){
            int x=i+dx,y=j+dy;
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==1 && !visited[x][y]){
                dfs(grid,x,y,visited);
            }
        }
    }

public:
    int minDays(vector<vector<int>>& grid){
        if(isDisconnected(grid)){
            return 0;
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(isDisconnected(grid)){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};
