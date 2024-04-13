class Solution {
public:
int largestArea(vector<int>& tab){
    stack<int> st;
    int maxA=0;
    int n=tab.size();
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i == n||tab[st.top()]>=tab[i])){
        int height=tab[st.top()];
        st.pop();
        int width;
        if(st.empty())
        width=i;
        else
        width=i-st.top()-1;
        maxA=max(maxA,width*height);
    }
    st.push(i);
}
return maxA;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        if(n==0)
        return 0;
        int m=matrix[0].size();
        int maxArea=0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                height[j]++;
                else
                height[j]=0;
            }
            int area=largestArea(height);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};