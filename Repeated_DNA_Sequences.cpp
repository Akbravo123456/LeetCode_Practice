class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        if(n<10)
        return {};

        unordered_map<string,int> b;
        for(int i=0;i<=n-10;i++){
            string temp=s.substr(i,10);
            b[temp]++;
        }

        vector<string> res;
        for(auto i:b){
            if(i.second>1)
            res.push_back(i.first);
        }
        return res;
    }
};