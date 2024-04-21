class Solution {
public:
bool dfs(vector<vector<int>>& graph,vector<int>& visited,int current,int end){
    if(current == end)
    return true;
    if(visited[current])
    return false;
    visited[current]=1;
    for(int neighbor : graph[current]){
        if(dfs(graph,visited,neighbor,end))
        return true;
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0);
        return dfs(graph,visited,source,destination);
    }
};