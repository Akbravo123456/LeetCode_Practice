class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;

        while(i<n && nums[i]< target){
            i++;
        }

        nums.insert(nums.begin()+i,target);
        return i;
    }
};