class Solution {
public:
    int mySqrt(int x) {
        long low=1;
        long high=x;
        while(low<=high){
            long long mid=(low+high)/2;
            long long sqr=mid*mid;
            if(sqr <= x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};