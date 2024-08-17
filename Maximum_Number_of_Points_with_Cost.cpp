class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();

        vector<long long> dp(n,0);
        for(int col=0;col<n;col++){
            dp[col]=points[0][col];
        }

        for(int row=1;row<m;row++){
            vector<long long> left(n,0);
            vector<long long> right(n,0);
            vector<long long> new_dp(n,0);

            left[0]=dp[0];
            for(int col=1;col<n;col++){
                left[col]=max(left[col-1],dp[col]+col);
            }

            right[n-1]=dp[n-1]-(n-1);
            for(int col=n-2;col>=0;col--){
                right[col]=max(right[col+1],dp[col]-col);
            }

            for(int col=0;col<n;col++){
                new_dp[col]=points[row][col]+max(left[col]-col,right[col]+col);
            }
            dp=new_dp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};