class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (board[i][j] == word[0] && visit(board, word, 0, i, j, n, m, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool visit(vector<vector<char>>& board,const string& word,int start,int x,int y,int n,int m,vector<vector<bool>>& visited) {
        if (start == word.size()) {
            return true;
        }

        if(x<0||x>=n||y<0||y>=m||visited[x][y]||board[x][y]!=word[start]) {
            return false;
        }
        visited[x][y] = true;

        bool found = visit(board,word,start+1,x+1,y,n,m,visited) ||
                     visit(board,word,start+1,x-1,y,n,m,visited) ||
                     visit(board,word,start+1,x,y+1,n,m,visited) ||
                     visit(board,word,start+1,x,y-1,n,m,visited);
        visited[x][y] = false;
        return found;
    }
};
