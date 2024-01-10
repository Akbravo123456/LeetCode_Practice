class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1){
            return false;
        }
        int common =1;
        for(int i=2;i*i<=num;i++){
        if(num%i==0){
            common +=i;

            if(i!=num/i){
                common +=num/i;
            }
        }
    }
    return common == num;
    }
};