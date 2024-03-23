class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= 0 || nums[i] > n)
            nums[i] = n+1;
        } 
        for(int i=0;i<n;i++){
            int index =abs(nums[i]) - 1;
            if(index >= 0 && index < n && nums[index] > 0)
            nums[index] *= -1;
        }
        for(int i=0; i<n;i++){
            if(nums[i]>0)
            return i+1;
        }
        return n+1;
    }
};