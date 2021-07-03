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
    int getHeight(TreeNode *root){
        if(!root) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left + 1, right + 1);
    }
    void levelOrder(TreeNode *root, vector<int>&ans){
        queue<pair<TreeNode*,int>>q;
        q.push({root, 1});
        while(not q.empty()){
            auto front = q.front();
            q.pop();
            if(front.first == NULL) continue;
            // cout<<front.first->val<<" "<<front.second<<"\n";

            ans[front.second] = max(ans[front.second], front.first->val);
            q.push({front.first->left, front.second + 1});
            q.push({front.first->right, front.second + 1});
        }
    }
        
    
    vector<int> largestValues(TreeNode* root) {
        if(not root) return {};
        int height = getHeight(root);
        vector<int>ans(height+1,INT_MIN);
        levelOrder(root,ans);
        ans = vector<int>(ans.begin() + 1, ans.end());
        return ans;
        
    }
};
/*
This one is BFS, with a node of the levels basically

*/
