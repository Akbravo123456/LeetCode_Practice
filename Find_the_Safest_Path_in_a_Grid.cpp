class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safety(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        vector<int> a={1, 0, -1, 0};
        vector<int> b={0, -1, 0, 1};

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]){
                    q.push({i,j});
                    safety[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto p=q.front();
            q.pop();
            int x =p.first,y=p.second;
            for (int k=0;k<4;k++) {
                int newx = x+a[k],newy=y+ b[k];
                if (newx >= 0 && newx<n && newy>=0 && newy<n && safety[newx][newy]>safety[x][y]+1){
                    safety[newx][newy]=safety[x][y]+1;
                    q.push({newx,newy});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({safety[0][0],{0,0}});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        while (!pq.empty()){
            int safe =pq.top().first,i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();
            if (i==n-1 && j==n-1){
                return safe;
            }
            for (int k=0;k<4;k++) {
                int ni=i+a[k],nj=j+b[k];
                if (ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj]) {
                    pq.push({min(safe,safety[ni][nj]),{ni, nj}});
                    vis[ni][nj]=1;
                }
            }
        }
        return 0;
    }
};