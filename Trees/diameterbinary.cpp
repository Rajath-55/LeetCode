/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int depth(TreeNode *root){
        if(!root) return 0;
        
        int lf = depth(root->left);
        int rh = depth(root->right);
        res = max(res, lf + rh +1);
        return 1 + max(lf, rh);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return --res;
    }
};
