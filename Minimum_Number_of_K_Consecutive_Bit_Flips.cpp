class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flipped=0;
        int res=0;
        vector<int> check(n,0);

        for(int i=0;i<n;i++){
            if(i>=k){
                flipped ^=check[i-k];
            }
            if(flipped==nums[i]){
                if(i+k>n){
                    return -1;
                }
                check[i]=1;
                flipped ^=1;
                res++;
            }
        }return res;
    }
};