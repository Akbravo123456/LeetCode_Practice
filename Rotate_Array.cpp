class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        if(k==n){
            return;
        }
        if(k>n){
            k=k%n;
        }
        vector<int> ans(n);
        int j=0;
        for(int i=n-k;i<n;i++){
            ans[j++]=nums[i];
        }
        for(int i=0;i<n-k;i++){
            ans[j++]=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
    }
};