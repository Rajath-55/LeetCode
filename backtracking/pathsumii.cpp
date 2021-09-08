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
    vector<vector<int>>res;
    
    void dfs(TreeNode *root, int target, vector<int>&paths){
        if(not root) return;
        if(not root->left and not root->right and target == root->val){
            paths.push_back(root->val);
            res.push_back(paths);
            paths.pop_back();
            return;
        }
        paths.push_back(root->val);
        dfs(root->left, target - root->val, paths);
        dfs(root->right, target - root->val, paths);
        paths.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>paths;
        dfs(root, targetSum, paths);
        return res;
    }
};
