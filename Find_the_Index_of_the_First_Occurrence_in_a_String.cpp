class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; 
        
        int hayLength = haystack.length();
        int needleLength = needle.length();
        
        if (hayLength < needleLength) return -1; 
        
        for (int i = 0; i <= hayLength - needleLength; i++) {
            int j;
            for (j = 0; j < needleLength; j++) {
                if (haystack[i + j] != needle[j]) {
                    break; 
                }
            }
            if (j == needleLength) {
                return i; 
            }
        }
        return -1; 
    }
};