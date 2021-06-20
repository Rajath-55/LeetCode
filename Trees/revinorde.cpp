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
    TreeNode* convertBST(TreeNode* root) {
        int prevVal = 0;
        revInorder(root, prevVal);
        return root;
    }
    void revInorder(TreeNode *root, int &prevVal){
        if(!root) return;
        revInorder(root->right, prevVal);
        root->val+=prevVal;
        prevVal = root->val;
        revInorder(root->left, prevVal);
       
    }
};
