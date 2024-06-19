class Solution {
public:
bool helper(int days, vector<int>& bloomDay, int m, int k){
    int K=0,bo=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=days){
            K++;
            if(K==k){
                bo++;
                K=0;
            }
        }
        else K=0;
    }
    return bo >=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1,h=1,n=bloomDay.size(),res=-1;
        if(m>(n/k)) return -1;
        for(int i=0;i<bloomDay.size();i++) 
        h=max(h,bloomDay[i]);
        while(l<=h){
            int mid=l+(h-l)/2;
            if(helper(mid,bloomDay,m,k)){
                res=mid;
                h=mid-1;
            }else
            l=mid+1;
        }
        return res;
    }
};