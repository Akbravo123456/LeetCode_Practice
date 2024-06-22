class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res_count=0;
        int count=0;
        int odd_count=0;
        vector<int> prefix(nums.size()+1,0);
        prefix[0]=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                odd_count++;
            }
            if(odd_count>=k){
                res_count +=prefix[odd_count-k];
            }
            prefix[odd_count]++;
        }
        return res_count;
    }
};