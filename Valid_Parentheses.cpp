class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map={
        {'}','{'},
        {')','('},
        {']','['}
        };
        stack<char> st;
        for(char c:s){
            if (map.count(c) == 0){
                st.push(c);
            }else{
                if (st.empty() || map[c] != st.top()){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};