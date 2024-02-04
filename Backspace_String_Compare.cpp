class Solution {
public:

string convert(string s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='#'){
            if(st.empty()) continue;
            else st.pop();
        }
        else
        st.push(s[i]);
    }
    string a="";
    while(st.empty()==false)
    {
        a+=st.top();
        st.pop();
    }
    return a;
}
    bool backspaceCompare(string s, string t) {
        string s1=convert(s);
        string s2=convert(t);
        return s1==s2;
    }
};