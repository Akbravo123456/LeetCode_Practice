class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]^arr[i-1];
        }
        int total=0;
        for(int j=0;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(pref[j]==pref[k]){
                        total+=(k-j-1);
                    }
                }
        }
        return total;
    }
};