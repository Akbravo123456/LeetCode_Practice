class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
       set<string>s;
       for(auto i:dictionary){
        s.insert(i);
       } 
       string ans="";
       sentence.push_back(' ');
       string temp="";
       for(int i=0;i<(int)sentence.size();i++){
        if(sentence[i]==' '){
        ans+=temp;
        ans+=(char)(' ');
        temp="";
       }
       else{
        temp+=(char)(sentence[i]);
        if(s.count(temp)){
            ans+=temp;
            ans+=(char)(' ');
            temp="";
            while(sentence[i]!=' ') i++;
        }
       }
    }
    ans.pop_back();
    return ans;
    }
};