class Solution {
public:
void dfs(vector<int>&v,vector<vector<int>>&vec ,int index, vector<int>& candidates, int target) {
    if(target==0){
            return vec.push_back(v);
        }
        if(target<0) return;
        for(int i = index; i<candidates.size() && target>=candidates[i]; i++){
            if(i==index || candidates[i]!=candidates[i-1]){
                v.push_back(candidates[i]);
                dfs(v,vec,i+1,candidates,target-candidates[i]);
                v.pop_back();
            }
        }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>vec;
        sort(candidates.begin(),candidates.end());
        dfs(v ,vec,0,candidates,target);
        return vec;
    }
};