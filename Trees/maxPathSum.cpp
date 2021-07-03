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
    int result = INT_MIN;
    
    
    int getSum(TreeNode *node){
        if(not node) return 0;
        int left = getSum(node->left);
        int right = getSum(node->right);
        
        int nodeInPath = max((max(left, right) + node->val), node->val);
        int nodeAsRoot = max(nodeInPath, left+right+node->val);
        result = max(result, nodeAsRoot);
        
        return nodeInPath;
        
    }
    
    int maxPathSum(TreeNode* root) {
        getSum(root);
        return result;
        
    }
};


/*
LOGIC:
Three cases:
1. Current node is in the path of maximum sum

2. Current node is the root of the maximum sum path

3. Current node is not in the path of the maximum sum

SOlve:
1. start at the root, maintain three variables for the three cases
2. left call made first, then right call
3. the three variables are:
maximum_straight_path, maximum_path_with_nodeasroot, result;
maximum_path_ith_nodeasroot is the maximum of itself and maximum_straght_oath
result is the maximum of result and maximum_path_ith_nodeasroot

evefy node can return only the path with the node in it ie case 1
because if that node were the root, any higher node cannot access that sum

O(n) complexity






*/
