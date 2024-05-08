class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted =score;
        sort(sorted.begin(),sorted.end(),greater<int>());
        vector<string> medals={"Gold Medal","Silver Medal","Bronze Medal"};
        unordered_map<int,string> rank;
        for(int i=0;i<sorted.size();i++){
            if(i<3){
                rank[sorted[i]]=medals[i];
            }else{
                rank[sorted[i]]=to_string(i+1);
            }
        }
        vector<string>result;
        for(int s:score){
            result.push_back(rank[s]);
        }
        return result;
    }
};