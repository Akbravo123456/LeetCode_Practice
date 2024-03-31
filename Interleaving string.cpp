class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(),n2 = s2.size(),n3 = s3.size();
        if(n1+n2!=n3)return false;
        if((s1==s3 && n2==0) || (s2==s3 && n1==0))return true;
        vector<int> dp(n2+1,-1);
        if(s3[0]==s1[0])dp[0] = 1;
        if(s3[0]==s2[0])dp[1] = 0;
        
        for(int i=1;i<n3;i++)
        {
            for(int j=n2;j>=0;j--)
            {
                if(dp[j]==-1)continue;
                if(j+1<= n2 && s2[j]==s3[i])
                    dp[j+1] = max(dp[j+1],dp[j]);
                if(s1[dp[j]]==s3[i])
                    dp[j] = dp[j]+1;
            }
        }
         
        return (dp.back()==n1);
    }
};