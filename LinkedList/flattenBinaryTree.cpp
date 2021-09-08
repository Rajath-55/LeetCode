class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return;
        }
        
        if(root->left!=NULL)
        {
            flatten(root->left);
            
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=NULL;
            
            TreeNode* tl=root->right;
            while(tl->right!=NULL)
            {
                tl=tl->right;
            }
            tl->right=temp;
        }
        
        flatten(root->right);
    }
};
