class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
        return "0";
        string ans="";
        int neg=0;
        if(num<0) neg=1,num = abs(num);
        while(num!=0){
            int mod=num%7;
            ans+=(char)(mod+'0');
            num/=7;
        }
        if(neg) ans.push_back('-');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};