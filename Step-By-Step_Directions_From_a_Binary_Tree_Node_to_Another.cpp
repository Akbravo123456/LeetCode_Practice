class Solution {
public: 
TreeNode* lca(TreeNode* root,int startValue,int destValue){
    if(!root) return NULL;
    if(root->val==startValue || root->val==destValue)
    return root;
    auto l=lca(root->left,startValue,destValue);
    auto r=lca(root->right,startValue,destValue);
    if(l && r) return root;
    return l ? l:r;
}
 bool search(TreeNode *root,int x,string& path){
    if(root==NULL)
    return false;
    if(root->val==x)
    return true;

    path+='L';
    if (search(root->left,x,path)) return true;
    path.pop_back();
    path +='R';
    if (search(root->right, x, path)) return true;
    path.pop_back();
    return false;
 }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root=lca(root,startValue,destValue);
        string p1,p2;
        search(root,startValue,p1);
        search(root,destValue,p2);
        for(auto& c:p1)
        c='U';
        return p1+p2;
    }
};