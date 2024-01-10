class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> loc;
        vector<string> row={
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        
        for(int i=0;i<row.size();i++){
            for(auto &ch:row[i]){
                loc.insert(make_pair(ch,i));
                loc.insert(make_pair(ch-'a'+'A',i));
            }
        }

        vector<string> onerowwords;
        for(auto &word: words){
            bool onerowword=true;
            for (int i = 1; i < word.size(); i++) {
                if(loc[word[i - 1]] != loc[word[i]]){
                    onerowword=false;
                    break;
                }
            }
            if(onerowword)
            onerowwords.push_back(word);
        }
        return onerowwords;
    }
};