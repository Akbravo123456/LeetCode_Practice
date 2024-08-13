class Solution {
public:
void inorder(TreeNode* node,vector<int>& res){
    if(!node) return;
    inorder(node->left,res);
    res.push_back(node->val);
    inorder(node->right,res);
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};