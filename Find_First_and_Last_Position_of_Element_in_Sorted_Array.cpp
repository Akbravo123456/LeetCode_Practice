class Solution {
public:
    int firstOccurence(vector<int> &nums,int target){
        int low=0,high=nums.size()-1,first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return first;
    }
    int secondOccurence(vector<int> &nums,int target){
        int low=0,high=nums.size()-1,second=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                second=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return second;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOccurence(nums,target);
        if(first==-1){
            return {-1,-1};
        }
        int second=secondOccurence(nums,target);
        return {first,second};
    }
};