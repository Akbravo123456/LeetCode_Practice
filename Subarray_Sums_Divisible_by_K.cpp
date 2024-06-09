class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k){
        unordered_map<int,int> remainder_count;
        remainder_count[0]=1;
        int sum=0;
        int count=0;
        for(int num:nums){
            sum +=num;
            int rem=sum%k;
            if(rem<0) rem +=k;
            if(remainder_count.find(rem)!=remainder_count.end()){
                count +=remainder_count[rem];
            }
            remainder_count[rem]++;
            }
            return count;
    }
};