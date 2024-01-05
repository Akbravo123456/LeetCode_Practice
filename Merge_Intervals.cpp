class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
        return intervals;

        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0];
        });

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(result.back()[1] >=intervals[i][0]){
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};