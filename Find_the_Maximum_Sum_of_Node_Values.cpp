class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0,bu=LLONG_MAX;
        int count=0;
        for(int el:nums){
            long long XV=el^k;
            if(XV>el){
                sum +=XV;
                bu=min(bu,XV-el);
                count++;
            }else{
                sum+=el;
                bu=min(bu,(long long)el-XV);
            }
        }
        if(count%2==0) {
            return sum;
        }
        return sum-bu;
    }
};