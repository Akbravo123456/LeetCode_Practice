class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<char> sorted(heights.begin(), heights.end());
        sort(heights.begin(),heights.end());
        int a=heights.size(),res=0;
        for(int i=0;i<a;i++)
        res+=(heights[i]!=sorted[i]);
        return res;
    }
};