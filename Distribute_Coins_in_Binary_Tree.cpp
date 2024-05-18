class Solution {
public:
    int count=0;
    int search(TreeNode* root) {
        if (root==NULL) return 0;
        int le=search(root->left);
        int ri=search(root->right);
        count+=abs(le)+abs(ri);
        return(le+ri+root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        search(root);
        return count;
    }
};