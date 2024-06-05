class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> chars(26,INT_MAX);
        for(const string& word:words){
            vector<int> curr(26,0);
            for(char c:word){
                curr[c-'a']++;
            }
            for(int i=0;i<26;i++){
                chars[i]=min(chars[i],curr[i]);
            }
        }
        vector<string> res;
        for(int i=0;i<26;i++){
            for(int j=0;j<chars[i];j++){
                res.push_back(string(1,'a'+i));
            }
        }
        return res;
    }
};