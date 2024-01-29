class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int>result;
        int wide=0;
        int line=0;
        int last_width=0;
        for(int i=0;i<s.length();i++){
            wide+=widths[(int)s[i]-97];
            if(wide==100){
                line++;
                wide=0;
            }
            else if(wide>100){
                line++;
                wide=0;
                i--;
            }
        }
        if(wide==0){
            last_width=100;
        }
        else{
            last_width=wide;
            line++;
        }
        result.push_back(line);
        result.push_back(last_width);
        return result;
    }
};