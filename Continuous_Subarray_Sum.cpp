class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(),prefSum=0;
        unordered_map<int,int> Occ;
        Occ[0]=0;
        for(int i=0;i<n;i++){
            prefSum=(prefSum+nums[i])%k;
            if(Occ.find(prefSum)!=Occ.end()){
                if (i+1 - Occ[prefSum]>=2) return true;
            }else{
                Occ[prefSum]=i+1;
            }
        }
        return false;
    }
};