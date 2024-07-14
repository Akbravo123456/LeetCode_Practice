class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.size(),i,j,k;
        vector<int> mulF(n,1);
        int mul=1;
        stack<int> temp;
        for(i=n-1;i>=0;i--){
            char ch=formula[i];
            if(ch==')'){
                string sdigit="";
                for(j=i+1;j<n;j++){
                    ch=formula[j];
                    if(!isdigit(ch)) break;
                    sdigit +=ch;
                }
                if(sdigit=="") sdigit="1";
                int digit=stoi(sdigit);
                mul=mul*digit;
                temp.push(digit);
            }
            else if(ch=='('){
                int digit=temp.top();
                temp.pop();
                mul=mul/digit;
            }
            mulF[i]=mul;
        }
        map<string,int>mp;
        for(int i=0;i<n;i++){
            char ch=formula[i];

            if(isupper(ch)){
                int mul=mulF[i];
                string ele="";
                ele +=ch;
                for(j=i+1;j<n;j++){
                    ch=formula[j];
                    if(!islower(ch)) break;
                    ele +=ch;
                }
                string sdigit="";
                for(k=j;k<n;k++){
                    ch=formula[k];
                    if(!isdigit(ch)) break;
                    sdigit +=ch;
                }
                if(sdigit == "")sdigit="1";
                int digit=stoi(sdigit);
                mp[ele] +=mul*digit;
                i=k-1;
            }
            else if(ch=='('){
                continue;
            }
            else if(ch==')'){
                continue;
            }
        }
        string ans="";
        for(auto p:mp){
            string ele=p.first;
            string sdigit=to_string(p.second);
            if(sdigit=="1") sdigit="";
            ans +=ele+sdigit;
        }
        return ans;
    }
};