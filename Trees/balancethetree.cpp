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
  
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        makeInorder(root, inorder);
        TreeNode *newRoot = makeTree(0, inorder.size() - 1, inorder);
        return newRoot;
        
    }
    void makeInorder(TreeNode *root, vector<int>&inorder){
        if(!root) return;
        makeInorder(root->left, inorder);
        inorder.push_back(root->val);
        makeInorder(root->right, inorder);
    
    }
    TreeNode *makeTree(int left, int right, vector<int>&inorder){
        if(left > right) return NULL;
        int mid =(left + right)/2;
        TreeNode *root = new TreeNode(inorder[mid]);
        root->left = makeTree(left,mid - 1, inorder);
        root->right = makeTree(mid + 1, right, inorder); 
        return root;
    }
};
