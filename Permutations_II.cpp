class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector <vector<int>> res;
       sort(nums.begin(),nums.end());
       dfs(nums, vector<bool>(nums.size()), {}, res);
       return res;
       }
       private:
       void dfs(const vector<int>& nums, vector<bool>&& used, vector<int>&& path,vector<vector<int>>& res){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(used[i])
            continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, move(used), move(path), res);
            path.pop_back();
            used[i] = false;
        }
       } 
};