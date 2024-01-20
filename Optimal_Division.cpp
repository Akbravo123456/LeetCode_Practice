class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return "";
        string num=to_string(nums[0]);
        if(n==1) 
        return num;
        string more="";
        for(int i=1;i<n;i++){
            more +=to_string(nums[i]);
            if(i!=n-1)
            more +="/";
        }
        if(n==2){
            return num+ "/" + more;
        }
        return num+"/"+"("+more+")";
    }
};