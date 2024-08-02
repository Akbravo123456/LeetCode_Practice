class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=0;

        for(int num:nums){
            ones +=(num == 1);
        }

        if(ones == 0) return 0;
        nums.insert(nums.end(),nums.begin(),nums.end());
        int ans=INT_MAX;
        int maxOnesInWindow=0,currentOnes=0;

        for(int i=0;i<ones;i++){
            currentOnes +=(nums[i]==1);
            }
            maxOnesInWindow=currentOnes;

            for(int i=1;i<n;i++){
                currentOnes -=(nums[i-1]==1);
                currentOnes +=(nums[i+ones-1]==1);
                maxOnesInWindow = max(maxOnesInWindow,currentOnes);
            }
        return ones - maxOnesInWindow;
    }
};