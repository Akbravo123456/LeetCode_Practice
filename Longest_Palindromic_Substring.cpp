class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return ""; 
        int maxLength = 1;
        int start = 0;     
        for (int i = 0; i < s.length(); ++i) {
            int left1 = i, right1 = i;
            while (left1 >= 0 && right1 < s.length() && s[left1] == s[right1]) {
                int len = right1 - left1 + 1;
                if (len > maxLength) {
                    maxLength = len;
                    start = left1;
                }
                left1--;
                right1++;
            }
            int left2 = i, right2 = i + 1;
            while (left2 >= 0 && right2 < s.length() && s[left2] == s[right2]) {
                int len = right2 - left2 + 1;
                if (len > maxLength) {
                    maxLength = len;
                    start = left2;
                }
                left2--;
                right2++;
            }
        }      
        return s.substr(start, maxLength); 
    }
};