class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=nums.size();
        if(s<=4){
            return 0;
        }
        int min_diff=INT_MAX;
        for(int i=0;i<=3;i++){
            int diff=nums[s-1-(3-i)]-nums[i];
            min_diff=min(min_diff,diff);
            }
            return min_diff;
    }
};