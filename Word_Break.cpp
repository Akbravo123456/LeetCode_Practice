class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> memo;
        return canSegmentString(s, wordSet, memo);
    }
    bool canSegmentString(const string& s, const unordered_set<string>& wordSet, unordered_map<string, bool>& memo) {
        if (s.empty()) return true;
        if (memo.find(s) != memo.end()) return memo[s];
        for (int i = 1; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            if (wordSet.find(prefix) != wordSet.end() && canSegmentString(s.substr(i), wordSet, memo)) {
                memo[s] = true;
                return true;
            }
        }
        memo[s] = false;
        return false;
    }
};