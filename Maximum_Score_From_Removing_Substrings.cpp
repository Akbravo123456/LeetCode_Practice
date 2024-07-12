class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        
        // Remove "ab" pairs first if x >= y, else remove "ba" pairs first
        if (x >= y) {
            score += removePairs(s, "ab", x);
            score += removePairs(s, "ba", y);
        } else {
            score += removePairs(s, "ba", y);
            score += removePairs(s, "ab", x);
        }
        
        return score;
    }

private:
    int removePairs(string &s,const string &pair,int gain) {
        stack<char>stk;
        int score=0;

        for (char c:s){
            if (!stk.empty() && stk.top()==pair[0] && c==pair[1]) {
                stk.pop();
                score +=gain;
            } else {
                stk.push(c);
            }
        }
        s.clear();
        while(!stk.empty()) {
            s +=stk.top();
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return score;
    }
};
