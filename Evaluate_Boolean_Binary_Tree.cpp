class Solution {
public:
bool ref(TreeNode* root){
    if(root->val==0||root->val==1){
        return root->val==1;
    }
    else if(root->val==2){
        return ref(root->left)||ref(root->right);
    }
    else if(root->val==3){
        return ref(root->left)&& ref(root->right);
    }
    return false;
}
    bool evaluateTree(TreeNode* root) {
        return ref(root);
    }
};