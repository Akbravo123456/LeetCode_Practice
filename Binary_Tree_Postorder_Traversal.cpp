class Solution {
public:
void helper(TreeNode* root,vector<int>& res){
    if(root==NULL) return;
    helper(root->left,res);
    helper(root->right,res);
    res.push_back(root->val); 
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    helper(root,res);
    return res;
}
};