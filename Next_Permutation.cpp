class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pt = n - 2;
        while (pt >= 0 && nums[pt] >= nums[pt + 1]) {
            pt--;
        }
        if (pt >= 0) {
            int i = n - 1;
            while (i > pt && nums[i] <= nums[pt]) {
                i--;
            }
            swap(nums[pt], nums[i]);
        }
        reverse(nums.begin() + pt + 1, nums.end());
    }
};
