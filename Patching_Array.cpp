class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0;
        int total_patch=0;
        long long sum=1;
        int le=nums.size();
        while(sum<=n){
            sum+=(i<le && nums[i]<=sum)?nums[i++]:sum;
            total_patch++;
        }
        return total_patch-i;
    }
};