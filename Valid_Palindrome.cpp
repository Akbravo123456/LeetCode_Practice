class Solution {
public:
    bool isPalindrome(string s) {
        string u="";
        for(char c:s){
            if(isalnum(c)){
                u +=tolower(c);
            }
        }
        string reversedstring = u;
        reverse(reversedstring.begin(),reversedstring.end());
        return u == reversedstring;
    }
};