class Solution {
public:
void del(TreeNode* root,TreeNode* d_node){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==d_node){
            temp=NULL;
            delete (d_node);
            return;
        }
        if(temp->right){
            if(temp->right==d_node){
                temp->right=NULL;
                delete (d_node);
                return;
            }else{
                q.push(temp->right);
            }
        }    
        if(temp->left){
            if(temp->left==d_node){
                temp->left=NULL;
                delete (d_node);
                return;
            }else{
                q.push(temp->left);
            }
        }    
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        if(root==NULL)
        return forest;

        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());

        function<TreeNode*(TreeNode*)> removeNodes=[&](TreeNode* node)->TreeNode* {
            if (node == NULL) return NULL;
            node->left =removeNodes(node->left);
            node->right =removeNodes(node->right);
            if (to_delete_set.find(node->val)!=to_delete_set.end()) {
                if (node->left) forest.push_back(node->left);
                if (node->right) forest.push_back(node->right);
                delete node;
                return NULL;
            }
            return node;
        };

        root = removeNodes(root);
        if (root != NULL) {
            forest.push_back(root);
        }
        return forest;
    }
};