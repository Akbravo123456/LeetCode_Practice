class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string alp[27]={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        set<string>s;
        for(int i=0;i<words.size();i++)
        {
            string curr="";
            for(auto c: words[i])
            {
                curr += alp[c-'a'];
            }
            s.insert(curr);
        }
        return s.size();
    }
};