class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int div=2;pow(div,2)<=c;div++){
            if(c%div == 0){
                int exp_count=0;
                while(c % div==0){
                    exp_count++;
                    c /=div;
                }
                if(div % 4 == 3 && exp_count % 2 !=0){
                    return false;
                }
            }
        }
        return c % 4 !=3;
    }
};