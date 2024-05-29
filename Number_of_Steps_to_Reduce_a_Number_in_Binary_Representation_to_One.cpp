class Solution {
public:
    int numSteps(string s) {
       if(s.size()==1)
       return 0;

       int count=0;
       for(int i=s.length()-1;i>0;){
        if(s[i]=='0'){
            count++;
            i--;
        }
        else{
            count++;
            while(s[i]=='1' && i>0){
                count++;
                i--;
            }
           if(i==0)
           count++;
           s[i]='1'; 
        }
       } 
       return count;
    }
};