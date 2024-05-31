class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result=0;
        for(int num:nums){
            result ^=num;
        }
        int p=result & -(unsigned int)result;
        int i=0,j=0;
        for(int num:nums){
            if(num & p){
                i ^=num;
            }
            else{
                j ^=num;
            }
        }
        return {i,j};
    }
};