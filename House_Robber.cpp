class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int,int> max_accum;
        return solve(max_accum,nums,nums.size() - 1);
        }
        int solve(unordered_map<int, int>& max_accum, vector<int>& nums, int i) {
            if(i==0)
            return nums[0];
            if(i==1)
            return max(nums[0],nums[1]);
            if(max_accum.find(i)!= max_accum.end())
            return max_accum[i];

            int take = solve(max_accum,nums,i-2) + nums[i];
            int notTake = solve(max_accum, nums, i - 1);
            max_accum[i] = max(take, notTake);
            return max_accum[i];
    }
};