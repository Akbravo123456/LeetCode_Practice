class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        track(s, 0, path, result);
        return result;
    }

    void track(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start==s.length()) {
            result.push_back(path);
            return;
        }

        for (int i=start;i<s.length();i++) {
            if (isPalindrome(s,start,i)) {
                path.push_back(s.substr(start,i-start+1));
                track(s,i+1,path,result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s,int start,int end) {
        while (start<end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};