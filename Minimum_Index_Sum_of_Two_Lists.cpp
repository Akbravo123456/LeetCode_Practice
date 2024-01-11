class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string,int> s;
        int n1=list1.size();
        int n2=list2.size();
        for(int i=0;i<n1;i++){
            string s1=list1[i];
            for(int j=0;j<n2;j++){
                if(list2[j]==s1){
                    s[list2[j]]=i+j;
                }
            }
        }
        int min=INT_MAX;
        for(auto it:s){
            if(it.second<=min){
                min=it.second;
            }
        }
        for(auto it:s){
            if(it.second == min){
                res.push_back(it.first);
            }
        }
        return res;
    }
};