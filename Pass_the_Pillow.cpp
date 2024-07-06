class Solution {
public:
    int passThePillow(int n, int time) {
        int t=n-1;
        int c=time/t;
        int p=time%t;
        if(c%2==0){
            return p+1;
        }else{
            return (t-p)+1;
        }
    }
};