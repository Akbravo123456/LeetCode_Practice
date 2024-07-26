class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(const auto& edge:edges){
            dist[edge[0]][edge[1]]=edge[2];
            dist[edge[1]][edge[0]]=edge[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]<INT_MAX && dist[k][j]<INT_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int res;
        int city_count=INT_MAX;
        for(int i=n-1;i>=0;i--){
        int count=0;
        for(int j=0;j<n;j++){
            if(dist[i][j]<=distanceThreshold && i!=j)
            count++;
        }
        if(count<city_count){
            res=i;
            city_count=count;
        }
    }
    return res;
    }
};