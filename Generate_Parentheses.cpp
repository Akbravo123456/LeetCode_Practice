class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        findAll("(", 1, 0, result, n);
        return result;
    }
    void findAll(string current, int o, int c, vector<string>& result, int n) {
        if (current.length() == 2 * n) {
            result.emplace_back(current);
            return;
        }
        if (o < n) findAll(current + "(", o + 1, c, result, n);
        if (c < o) findAll(current + ")", o, c + 1, result, n);
    }
};