class Solution {
public:
     int minOperations(vector<int>& nums,int k) {
        int xor_sum = 0;
        for (int num : nums) {
            xor_sum ^= num;
        }
        int target = k ^ xor_sum;
        return countSetBits(target);
    }

private:
    int countSetBits(int num) {
        int count = 0;
        while (num) {
            num &= (num - 1);
            count++;
        }
        return count;
    }
};