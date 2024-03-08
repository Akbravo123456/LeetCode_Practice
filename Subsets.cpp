class Solution {
public:
    void findSubsets(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);

        for (int i = idx; i < nums.size(); i++) {
            subset.push_back(nums[i]); 
            findSubsets(nums, i + 1, subset, result); 
            subset.pop_back(); 
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        findSubsets(nums, 0, subset, result);
        return result;
    }
};
