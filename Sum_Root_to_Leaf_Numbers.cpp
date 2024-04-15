class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<pair<TreeNode* ,int>> stack={{root,0}};
        int sum=0;
        TreeNode* node=root;
        while(!stack.empty()){
            auto[node,d]=stack.back();
            stack.pop_back();
            d=10*d+node->val;
            if(!node->left && !node->right)
            sum+=d;
            if(node->right) stack.emplace_back(node->right,d);
            if(node->left) stack.emplace_back(node->left,d);
        }
        return sum;
    }
};