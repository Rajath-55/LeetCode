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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        makeinorder(res,root);
        return res[k-1];
    }
    
    void makeinorder(vector<int>&res, TreeNode *root){
        if(!root) return;
        makeinorder(res, root->left);
        res.push_back(root->val);
        makeinorder(res, root->right);
    }
};
