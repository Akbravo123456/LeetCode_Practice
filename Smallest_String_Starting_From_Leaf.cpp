class Solution {
string result;
public:
    void solve(TreeNode* root,string running) {
        if (root == nullptr) return;
        running += (root->val + 'a');
        if(root->left == NULL && root->right == NULL){
            reverse(running.begin(),running.end());
            if(result.empty() || running < result){
                result = running;
            }
            return;
        }
        solve(root->left, running);
        solve(root->right, running);
    }
    string smallestFromLeaf(TreeNode* root){
        result="";
        solve(root,"");
        return result;
    }
};