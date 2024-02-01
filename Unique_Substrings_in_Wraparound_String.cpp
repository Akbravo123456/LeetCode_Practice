class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> mlen(26,0);
        int ans=0;
        int currlen=0;
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            int curr=s[i];
            if(i>0 && (curr - s[i-1]+26)% 26 == 1){
                currlen++;
            }else{
                currlen=1;
            }
            int index= curr - 'a';
            mlen[index] = max(mlen[index],currlen);
        }
        for(int len:mlen)
        ans +=len;
        return ans;
    }
};