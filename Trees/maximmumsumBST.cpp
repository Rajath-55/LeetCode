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
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        
        helper(root, ans);
        
        return ans;
    }
    
    tuple<int, int, int> helper(TreeNode* root, int& ans) { // min, max, sum
        if (not root) {
            // base case
            return {INT_MAX, INT_MIN, 0};
        }
        
        auto [leftMin, leftMax, leftSum] = helper(root->left, ans);
        auto [rightMin, rightMax, rightSum] = helper(root->right, ans);
        
        if (root->val > leftMax and root->val < rightMin) {
            // valid bst
            int sum = leftSum + root->val + rightSum;
            ans = max(ans, sum);

            return {min(root->val, leftMin), max(root->val, rightMax), sum};
        }
        
        // invalid bst
        return {INT_MIN, INT_MAX, 0};
    }
};


/*
postorder traversal is the key here
we process any node only when its left and right subtrees are processed
that guarantees that if the subtree rooted at node i is a BST then
its parent can be checked

- Single nodes are always BST

we are going to make a struct, which keeps track of :
a bool checking if its a BST
the size of the subtree rooted at the given node
the node itself
the maximum element of the subtree rooted at node
the minumum eement of the subtree rooted at node


O(N) approach where N is no of nodes in the tree

*/
