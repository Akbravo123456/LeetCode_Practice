class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        for(auto it:descriptions){
            TreeNode *parentNode,*childNode;

            if(mp.find(it[0])!=mp.end()){
                parentNode=mp[it[0]];
            }else{
                parentNode=new TreeNode(it[0]);
                mp[it[0]]=parentNode;
            }
            if(mp.find(it[1])!=mp.end()){
                childNode=mp[it[1]];
            }else{
                childNode=new TreeNode(it[1]);
                mp[it[1]]=childNode;
            }
            if(it[2]==1){
                parentNode->left=childNode;
            }else{
                parentNode->right=childNode;
            }
    }

    unordered_map<int,int> storeChild;
    for(auto it:descriptions){
        storeChild[it[1]]=1;
    }

    TreeNode* root;
    for(auto it:descriptions){
        if(storeChild.find(it[0])==storeChild.end()){
            root=mp[it[0]];
        }
    }
    return root;
    }
};