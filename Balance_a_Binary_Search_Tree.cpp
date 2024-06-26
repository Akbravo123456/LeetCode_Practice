class Solution {
void inorderTraversal(TreeNode* root,vector<int>& nodes){
   if(root == NULL) return;
   inorderTraversal(root->left,nodes);
   nodes.push_back(root->val);
   inorderTraversal(root->right,nodes);
}

TreeNode* BuildbalanceBST(const vector<int>& nodes,int start,int end){
   if(start>end) return NULL;
   int mid=start+(end-start)/2;
   TreeNode* node=new TreeNode(nodes[mid]);
   node->left=BuildbalanceBST(nodes,start,mid-1);
   node->right=BuildbalanceBST(nodes,mid+1,end);
   return node;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodes;
    inorderTraversal(root,nodes);
    return BuildbalanceBST(nodes,0,nodes.size()-1);
    }
};