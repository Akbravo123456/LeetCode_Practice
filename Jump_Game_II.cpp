class Solution {
public:
    int jump(vector<int>& nums) {
        int totalJumps=0;
        int destination=nums.size()-1;
        int coverage=0,lastJumpIndex=0;
        if(destination==0) return 0;
        for(int i=0;i<destination;i++){
            coverage=max(coverage,i+nums[i]);
            if(i==lastJumpIndex){
                lastJumpIndex=coverage;
                totalJumps++;
                if(coverage >= destination){
                    return totalJumps;
                }
            }
        }
        return totalJumps;
    }
};