class Solution {
public:
unordered_map<string,vector<string>> mp;
unordered_set<string> dict;
vector<string> combine(vector<string> prev,string word){
    for(int i=0;i<prev.size();i++){
        prev[i] +=" "+word;
    }
    return prev;
}

vector<string> wordBreakUtil(string s){
    if(mp.find(s)!=mp.end())
    return mp[s];
    vector<string> res;
    if (dict.find(s)!=dict.end())
    res.push_back(s);
    for(int i=1;i<s.length();i++){
       string word=s.substr(i);
       if(dict.find(word)!=dict.end()){
        string rem=s.substr(0,i);
        vector<string> prev=combine(wordBreakUtil(rem),word);
        res.insert(res.end(),prev.begin(),prev.end());
       } 
    }
    mp[s]=res;
    return res;
}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        mp.clear();
        dict.clear();
        dict.insert(wordDict.begin(),wordDict.end());
        return wordBreakUtil(s);
    }
};