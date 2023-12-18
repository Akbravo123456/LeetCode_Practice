class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> usedIntegers;
        while(true){
            int sum=0;
            while (n!=0){
                sum +=pow(n%10,2.0);
                n=n/10;
            }
            if (sum==1) return true;
            n=sum;
            if(usedIntegers.find(n)!=usedIntegers.end())
            return false;
            usedIntegers.insert(n);
        }
    }