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
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;
    map<int, int> mp; // using map to get the nodes sorted according to their depth

    traverse(root,0,mp);

    for (auto i=mp.begin();i!=mp.end();i++) ans.push_back(i->second);

    return ans;
}

void traverse(TreeNode *root, int depth, map<int, int> &mp) {
    if(!root) return;

    if(mp.count(depth)==0) mp[depth] = root->val;

    traverse(root->right,depth+1,mp); // because we need the extreme right
    traverse(root->left,depth+1,mp);
}
};
