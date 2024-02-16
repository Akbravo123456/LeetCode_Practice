class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
            return {};
        }

        unordered_map<char,string> mp ={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        string cur="";
        vector<string> result;
        dfs(digits,0,mp,cur,result);
        return result;
    }
    private:
    void dfs(string digits, int index, unordered_map<char, string>& mp, string& cur, vector<string>& result){
        if(index == digits.size()){
            result.push_back(cur);
            return;
        }
        string str = mp[digits[index]];
        for(int i=0;i<str.size();i++){
            cur.push_back(str[i]);
            dfs(digits,index+1,mp,cur,result);
            cur.pop_back();
        }
    }
};