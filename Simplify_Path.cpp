class Solution {
public:
    string simplifyPath(string path) {
        stack <char> s;
        int n=path.length();

        for(int i=0; i<n; i++){
            if((i==n-1 && path[i]=='/') || (!s.empty() && (s.top()=='/' && path[i]=='/'))) continue;
            else if(path[i]=='.' && path[i-1]=='/'){
                int count=0;
                int id=i;
                while(id < n){
                    if(path[id]!='.') break;
                    count++;
                    id++;
                }
                if(count==1 && path[id]!='/' && id!=n){
                    s.push('.');
                }
                if(count==2 && (id==n || path[id]=='/')){
                    s.pop();
                    while( !s.empty()){
                        if(s.top() =='/') break;
                         s.pop();
                    }
                }
                else if(count>=2){
                    while(count--){
                        s.push('.');
                    }
                }
                i=id-1;
            }

            else s.push(path[i]);
        }
        if(s.empty()) return "/";
        if(s.size()!=1 && s.top()=='/') s.pop();
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};