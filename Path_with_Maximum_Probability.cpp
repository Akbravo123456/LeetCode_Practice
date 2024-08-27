class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> mp(n,0.0);
        mp[start_node]=1.0;
        for(int i=0;i<n-1;i++){
            bool upd=false;
            for(int j=0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if(mp[u]*prob>mp[v]) {
                    mp[v]=mp[u] *prob;
                    upd= true;
                }
                if(mp[v]*prob>mp[u]) {
                    mp[u] = mp[v] * prob;
                    upd= true;
                }
            }
            if(!upd) break;
        }
        return mp[end_node];
    }
};