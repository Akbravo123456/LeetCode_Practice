class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int gap = numeric_limits<int>::max();

        for(int i=0;i < nums.size() - 2; i++){
            int l = i + 1;
            int r = nums.size() - 1;

            while(l<r){
                int sum = nums[i] + nums[l] + nums [r];
                if(sum < target){
                    int ngap = target - sum;
                    if(ngap < gap){
                        gap = ngap;
                        res = sum;
                    }
                    l++;
                }else if(sum > target){
                    int ngap = sum - target;
                    if(ngap < gap){
                        gap = ngap;
                        res = sum;
                    }
                    r--;
                }else{
                    return sum;
                }
            }
        }
        return res;
    }
};