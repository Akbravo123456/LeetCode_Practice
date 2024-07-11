class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string res;
        for(char ch:s){
            if(ch=='('){
              st.push(res);
              res.clear();  
            }
            else if(ch ==')'){
                reverse(res.begin(),res.end());
                if(!st.empty()){
                    res=st.top()+res;
                    st.pop();
                }
            }else{
                res +=ch;
            }
        }
        return res;
    }
};