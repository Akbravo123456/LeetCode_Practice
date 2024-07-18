class Solution {
public:
vector<int> dfs(TreeNode* root, int distance,int& ans){
    vector<int> d(distance+1);
    if(root==NULL) return d;
    if(root->left==NULL && root->right==NULL){
        d[0]=1;
        return d;
    }
    vector<int> l=dfs(root->left,distance,ans);
    vector<int> r=dfs(root->right,distance,ans);
    for(int i=0;i<distance;i++)
    for(int j=0;j<distance;j++)
    if(i+j+2<=distance)
    ans +=l[i]*r[j];

    for(int i=0;i<distance;i++)
    d[i+1]=l[i]+r[i];
    return d;
}
    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        dfs(root,distance,ans);
        return ans;
    }
};