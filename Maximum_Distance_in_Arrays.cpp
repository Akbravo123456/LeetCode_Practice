class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN=arrays[0].front();
        int MAX=arrays[0].back();
        int result=0;
        for(int i=1;i<arrays.size();i++){
            int currmin=arrays[i].front();
            int currmax=arrays[i].back();

            result=max({result,abs(currmin-MAX),abs(currmax-MIN)});

            MAX=max(MAX,currmax);
            MIN=min(MIN,currmin);
        }
        return result;
    }
};