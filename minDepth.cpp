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
    int minDepth(TreeNode* root) {
        int mini = INT_MAX;
        if(!root) return 0;
        helper(root, mini,1);  
        return mini;
    }
    void helper(TreeNode *head, int &mini, int depth){
        cout<<head->val<<" "<<mini<<" "<<depth<<endl;
        if(!head->left && !head->right) mini = min(mini, depth);
        if(head->left) helper(head->left, mini, depth + 1);
        if(head->right) helper(head->right, mini, depth + 1);
    }
};
