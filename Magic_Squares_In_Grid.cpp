class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(ms(grid,i,j)){
                    res++;
                }
            }
        }
        return res;
    }
    bool ms(vector<vector<int>>& grid,int i,int j){
        if(i+2<grid.size() && j+2<grid[i].size()){
            int col1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
            int col2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
            int col3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
            int row1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
            int row2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
            int row3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
            int dig1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
            int dig2=grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
            if(
                (col1 == col2) && (col1 == col3) && (col1 == row1) && (col1 == row2) && (col1 == row3) && (col1 == dig1) && (col1 == dig2)
            ){
                set<int> s({1,2,3,4,5,6,7,8,9});
                for(int r=0;r<3;r++){
                    for(int c=0;c<3;c++){
                        s.erase(grid[i+r][j+c]);
                    }
                }
                return s.empty();
            }
        }
        return false;
    }
};