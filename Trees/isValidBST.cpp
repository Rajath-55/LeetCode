class Solution {
public:
    TreeNode* prev=NULL;
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
       if(!isValidBST(root->left))
          return false;
       if(prev && root->val <=prev->val)
           return false;
        prev=root;
        return isValidBST(root->right);
    }
};
