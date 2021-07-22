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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool zigzag = true;
        
        while(!q.empty()){
            int size = q.size();
            zigzag = !zigzag;
            vector<int>temp;
            for(int i = 0; i < size; ++i){
                auto front = q.front();
                q.pop();
                temp.push_back(front->val);
                
                    if(front->left) q.push(front->left);
                    if(front->right) q.push(front->right);
                 
            }
            if(zigzag) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
        
        
    }
};

/*
Level count BFS with a flag to add left first then right or vice versa
*/
