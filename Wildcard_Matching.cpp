class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        bool mat[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++)
            mat[i][j]=false;
        }
        mat[0][0]=true;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*')
            mat[0][i]=mat[0][i-1];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1] == '*')
                mat[i][j] = mat[i][j-1] || mat[i-1][j];
                else if(p[j-1]=='?')
                mat[i][j] = mat[i-1][j-1];
                else if(s[i-1]==p[j-1])
                mat[i][j]=mat[i-1][j-1];
                else mat[i][j]=false;
            }
        }
        return mat[m][n];
    }
};