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
    vector<TreeNode*>res;
    unordered_map<string, vector<TreeNode*>> mp;
    string inorder(TreeNode *node){
        if(not node) return "";
        string temp = "(" + inorder(node->left) + to_string(node->val) + inorder(node->right) + ")";
        mp[temp].push_back(node);
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        inorder(root);
        for(auto x : mp){
            if(x.second.size() > 1){
                res.push_back(x.second[0]);
            }
        }
        
        return res;
    }
};

/*
Add subtrees with parantheses separating each subtree so that
a unique string is generated for every valid subtree.
Then check map if count > 1 and so on
now, keep a map with vector of TreeNodes, where if there are more than one element
then there have been two unique subtrees with the same values
then push one of them into result
O(n) time and space

*/
