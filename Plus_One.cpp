class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        for(int i=n;i>=0;i--){
            if (i==n){
                digits[i]++;
            }
            if(digits[i]==10){
                if(i!=0){
                    digits[i]=0;
                    digits[i-1]++;
                }
                else{
                    digits.push_back(0);
                    digits[i]=1;
                }
            }
        }
        return digits;
    }
};