class Solution {
public:
 int thirdMax(vector<int>& nums) {
        if(nums.size()==1){          
         return nums[0];   
        }
        if(nums.size()==2){           
            return max(nums[0],nums[1]);
        }

        int First_max=*max_element(nums.begin(),nums.end());   
	    int Second_max=INT_MIN;
        int Third_max=INT_MIN;
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(Second_max<nums[i] && nums[i]!=First_max){
                Second_max=nums[i];
                count1++;
            }
        }

        if(count1==0) return First_max; 
        int count2=0;
        for(int i=0;i<nums.size();i++){
            if((Third_max<nums[i] || nums[i]==INT_MIN) && ( nums[i]!=First_max &&  nums[i]!=Second_max)){
                Third_max=nums[i];
                count2++;
            }
        }
        if(count2>0){
            return Third_max;
        }else{
            return First_max;
        }
    }
};