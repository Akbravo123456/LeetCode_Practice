class Solution {
public:
vector<int> a;
void helper(Node* root){
    if(root==NULL) return;
    for(Node* r:root->children)
    helper(r);
    a.push_back(root->val);
}
    vector<int> postorder(Node* root) {
        helper(root);
        return a;
    }
};