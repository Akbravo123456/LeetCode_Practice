class Solution {
public:
    int beautifulSubsets(vector<int>& nums,int k) {
        unordered_map<int, int> countMap;
        int result=0;
        sort(nums.begin(),nums.end());
        vector<int> currentSubset;
        backtrack(0,nums,k,currentSubset,countMap,result);
        return result;
    }

    void backtrack(int index,const vector<int>& nums,int k,vector<int>& currentSubset,unordered_map<int, int>& countMap,int& result){
        if(index == nums.size()){
            if(!currentSubset.empty()) { 
                result++;
            }
            return;
        }

        if(countMap[nums[index]-k]==0) {
            currentSubset.push_back(nums[index]);
            countMap[nums[index]]++;
            backtrack(index + 1,nums,k,currentSubset,countMap,result);
            countMap[nums[index]]--;
            currentSubset.pop_back();
        }
        backtrack(index+1,nums,k,currentSubset,countMap,result);
    }
};
