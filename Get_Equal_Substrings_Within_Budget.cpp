class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int start=0;
        int curr=0;
        int maxlen=0;

        for(int i=0;i<n;i++){
            curr +=abs(s[i]-t[i]);

            while(curr>maxCost){
                curr -=abs(s[start]-t[start]);
                start++;
            }

            maxlen=max(maxlen,i-start+1);
        }
        return maxlen;
    }
};