/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool check(TreeNode *root,TreeNode *node){
    if(!root) return false;
    if(root==node) return true;
    return check(root->left,node) || check(root->right,node);
}

void giveAns(TreeNode *root,TreeNode* &ans,TreeNode *p,TreeNode *q){    
    if(!root) return;
    giveAns(root->left,ans,p,q);
    giveAns(root->right,ans,p,q);
    if(check(root,p) && check(root,q) && !ans) ans=root;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans=NULL;
        giveAns(root,ans,p,q);
        return ans;
    }
};
