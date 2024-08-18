class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return 0;
        int two_idx=0;
        int three_idx=0;
        int five_idx=0;

        vector<int>ugly;
        ugly.push_back(1);
        
        while(ugly.size()<n){
            int b2=ugly[two_idx]*2;
            int b3=ugly[three_idx]*3;
            int b5=ugly[five_idx]*5;

            int mini=min(b2,min(b3,b5));
            ugly.push_back(mini);

            if(mini == b2) two_idx++;
            if(mini == b3) three_idx++;
            if(mini == b5) five_idx++;
        }
        return ugly[n-1];
    }
};