class Solution {
public:
    int appendCharacters(string s, string t) {
        int slen=s.length();
        int tlen=t.length();
        int s_index=0;
        int t_index=0;

        while(s_index<slen && t_index<tlen){
            if(s[s_index]==t[t_index]){
                t_index++;
            }
            s_index++;
        }
        return tlen-t_index;
    }
};