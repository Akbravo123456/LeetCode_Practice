class Solution {
    int cp(const vector<int>& numbers,int distance){
        int count=0,left=0;
        for(int right=1;right<numbers.size();right++){
            while(numbers[right]-numbers[left]>distance){
                left++;
            }
            count +=right-left;
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        int low=0;int high=nums.back()-nums.front();
        while(low<high){
            int mid=low+(high-low)/2;
            if(cp(nums,mid)<k){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
};
