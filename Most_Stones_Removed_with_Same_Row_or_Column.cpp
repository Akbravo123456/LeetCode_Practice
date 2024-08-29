class Solution {
public:
void dfs(int &n,int idx,vector<bool>& vis,vector<vector<int>>& stones){
    vis[idx]=true;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(stones[idx][0]==stones[i][0])
            dfs(n,i,vis,stones);
            if(stones[idx][1]==stones[i][1])
            dfs(n,i,vis,stones);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int group=0;

        vector<bool>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(n,i,vis,stones);
                group +=1;
            }
        }
        return n-group;
    }
};