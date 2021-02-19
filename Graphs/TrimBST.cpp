<<<<<<< HEAD
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       if(!root)
           return NULL;
        if(root->val < low)
            return trimBST(root->right, low,high);
        if(root->val > high)
            return trimBST(root->left, low,high);
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low,high);
        return root;
            
    }
=======
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       if(!root)
           return NULL;
        if(root->val < low)
            return trimBST(root->right, low,high);
        if(root->val > high)
            return trimBST(root->left, low,high);
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low,high);
        return root;
            
    }
>>>>>>> 673ed86091449e4adc8c32e9546b1b85b39181ad
};