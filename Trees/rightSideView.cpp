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
    map<int,int>mp;
    void addDepths(TreeNode *node, int currDepth){
        if(not node) return;
        if(mp.find(currDepth) == mp.end())
         mp[currDepth] = node->val;
        addDepths(node->right, currDepth+1);
        addDepths(node->left, currDepth + 1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        addDepths(root, 0);
        vector<int>ans;
        for(auto x : mp)
            ans.push_back(x.second);
        return ans;
    }
};

/*
Some sort of a map
map that keeps depth and the value at that 
at each level, first check the whole right side, if there is a right tree of a rightside node, add that to 
the particular level, otherwise check the left side of the right subtree and add to map.
if there is a level that is not filled, it then gets filled form the left subtree
O(N) time and space complexity.
has to be a treemap ie not an unordered map because sorted order is not maintained
otherwise sorting on levels must be done which leads to nlogn time either way.

O(NlogN)
*/
